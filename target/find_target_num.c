/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:51:56 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/13 18:53:34 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "target.h"

t_dict *	find_most_profit_num (t_stack *a, t_stack *b, char flag) 
{
	t_element	*tmp_a;
	t_element	*target;
	t_dict		*step_dict;
	t_dict		*step_h_dict;
	t_dict		*dict;
	
	target = malloc(sizeof(t_element));
	if (!target)
		ft_error();
	tmp_a = a->top;
	step_h_dict = create_dictinary(a);
	step_dict = step_h_dict;
	while(tmp_a)
	{
		dict = find_value(tmp_a->data, b, create_dictinary(b));
		target->data = define_target(dict, flag, b, tmp_a);
		step_dict->a_int = tmp_a->data;
		step_dict->b_int = target->data;
		step_dict->value = count_steps(a, b, tmp_a, target);
		tmp_a = tmp_a->next;
		step_dict = step_dict->next;
	}
	free_dict(dict);
	free(target);
	return (step_find_min(step_h_dict));
}

int		define_target(t_dict* head_dict, char flag, t_stack *b, t_element* a_move) // находит target-числло из b  для ОДНОГО числа из стака а
{
	t_dict *dict_node;
	int pos;
	int neg;
	int	target;
	
	dict_node = head_dict;
	pos = 0;
	neg = 0;
	if ((a_move->data > find_max(b)->data || a_move->data < find_min(b)->data))
		return (find_min(b)->data);
	while(dict_node)
	{
		if (dict_node->value >= 0)
			pos++;
		else if (dict_node->value < 0)
			neg++;
		dict_node = dict_node->next;
	}
	target = find_target(head_dict, pos, neg, flag);
	return (target);
}

int		find_target(t_dict* head_dict, int pos, int neg, char flag)
{
	t_dict	*dict_node;
	int		target;
	int		i;

	i = 0;
	target = 0;
	dict_node = head_dict;
	while(dict_node)
	{
		i++;
		dict_node = dict_node->next;
	}
	if (i == pos)
		target = l_find_min(head_dict);
	else if (i == neg)
		target = l_find_max(head_dict);
	else if (i != neg && i != pos)
	{
		if (flag == 'a')
			target = l_find_min_pos(head_dict, pos);
		else if (flag == 'b')
			target = l_find_max_neg(head_dict, neg);		
	}
	return (target);
}

t_dict*	find_value(int num_a, t_stack *b, t_dict *head_dict) // находит все value для ОДНОГО числа из стака а
{
	t_element *tmp_b;
	t_dict *dict_node;

	tmp_b = b->top;
	dict_node = head_dict;
	// работать только с одниим числом из стака а
	while(tmp_b)
	{
		dict_node->a_int = num_a; // у list-a!!!!
		dict_node->value = num_a - tmp_b->data;
		dict_node->b_int = tmp_b->data;
		dict_node = dict_node->next;
		tmp_b = tmp_b->next;
	}
	return (head_dict);
}

int		l_find_min_pos(t_dict *head_dict, int pos)
{
	t_dict *dict;

	dict = head_dict;
	if (pos == 1)
		return (l_find_max(head_dict));
	
	while(dict)
	{
		if (dict->value < 0)
			dict->value = 2147483647;
		dict = dict->next;
	}
	return (l_find_min(head_dict));
}

int		l_find_max_neg(t_dict *head_dict, int neg)
{
	t_dict *dict;

	dict = head_dict;
	if (neg == 1)
		return (l_find_min(head_dict));
	while(dict)
	{
		if (dict->value > 0)
			dict->value = -2147483648;
		dict = dict->next;
	}
	return (l_find_max(head_dict));
}