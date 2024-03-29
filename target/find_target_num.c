/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:51:56 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/24 18:34:38 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "target.h"

t_dict	*find_most_profit_num(t_stack *a, t_stack *b, char flag)
{
	t_elem	*tmp_a;
	t_dict	*step_d;
	t_dict	*step_h_d;
	t_dict	*h_dict;

	step_h_d = create_dictinary(a);
	h_dict = create_dictinary(b);
	if (!step_h_d || !h_dict)
		return (NULL);
	tmp_a = a->top;
	step_d = step_h_d;
	while (tmp_a)
	{
		step_d->a_int = tmp_a->data;
		step_d->b_int = target(value(tmp_a->data, b, h_dict), flag, b, tmp_a);
		step_d->value = count_steps(a, b, tmp_a, step_d->b_int);
		tmp_a = tmp_a->next;
		step_d = step_d->next;
	}
	free_dict(h_dict);
	return (step_h_d);
}

// находит target-число из b  для ОДНОГО числа из стака а
int	target(t_dict *h_dict, char flag, t_stack *b, t_elem *a_move)
{
	t_dict	*dict_node;
	int		pos;
	int		neg;
	int		target;

	dict_node = h_dict;
	pos = 0;
	neg = 0;
	if ((a_move->data > find_max(b)->data || a_move->data < find_min(b)->data))
		return (find_min(b)->data);
	while (dict_node)
	{
		if (dict_node->value >= 0)
			pos++;
		else if (dict_node->value < 0)
			neg++;
		dict_node = dict_node->next;
	}
	target = which_target(h_dict, pos, neg, flag);
	return (target);
}

int	which_target(t_dict *head_dict, int pos, int neg, char flag)
{
	t_dict	*dict_node;
	int		target;
	int		i;

	i = 0;
	target = 0;
	dict_node = head_dict;
	while (dict_node)
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

// находит все value для ОДНОГО числа из стака а
t_dict	*value(int num_a, t_stack *b, t_dict *head_dict)
{
	t_elem	*tmp_b;
	t_dict	*dict_node;

	tmp_b = b->top;
	dict_node = head_dict;
	while (tmp_b)
	{
		dict_node->a_int = num_a;
		dict_node->value = num_a - tmp_b->data;
		dict_node->b_int = tmp_b->data;
		dict_node = dict_node->next;
		tmp_b = tmp_b->next;
	}
	return (head_dict);
}
