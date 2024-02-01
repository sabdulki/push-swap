/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:51:56 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/01 17:31:43 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "target.h"

t_dict *	find_most_profit_num (t_stack *a, t_stack *b) 
{
	t_element *tmp_a;
	// t_element *tmp_b;
	t_dict *step_dict;
	t_dict *step_h_dict;
	t_dict *head_dict;
	t_dict *dict;
	t_element *target;
	int steps;
	t_dict*	moving_num;
	
	target = malloc(sizeof(t_element));
	tmp_a = a->top;
	// tmp_b = b->top;

	head_dict = create_dictinary(b);
	step_h_dict = create_dictinary(a);
	step_dict = step_h_dict;
	while(tmp_a)
	{
		dict = find_value(tmp_a->data, b, head_dict);
		target->data = find_target(dict, a, b);
		step_dict->a_int = tmp_a->data;
		step_dict->b_int = target->data;
		printf("\ntarget for '%d' number of 'a' stack is: %d\n", tmp_a->data, target->data);
		// я нашла число, к которому пойдет первое число из стака а.
		// теперь мне надо посчитать количество шагов для первого числа из стака а до его таргета.
		steps = count_steps(a, b, tmp_a, target);
		step_dict->value = steps;
		// printf("have to accomplish  %d  steps to move num\n", steps);
		tmp_a = tmp_a->next;
		step_dict = step_dict->next;
	}
	// print_list(step_h_dict);
	//теперь беру step_h_dict и ищу в нем самый маленький value. Возвращаю чилсо int_a и 
	// отдельной функцией совершаю перемещение (move).
	moving_num = step_find_min(step_h_dict);
	//free (step-h_dict);
	printf("the moving num is: %d\n", moving_num->a_int);
	return (moving_num);
}

int		find_target(t_dict* head_dict, t_stack *a, t_stack *b) // находит target-числло из b  для ОДНОГО числа из стака а
{
	t_dict *dict_node;
	int target;
	int pos;
	int neg;
	int i;
	
	dict_node = head_dict;
	target = 0;
	pos = 0;
	neg = 0;
	i = 0;
	target = target_for_max_min(dict_node, a, b);
	if (target != 0) // NOT SAFE!!!!
	{
		// free_dict(head_dict);
		return (target);
	}
	while(dict_node)
	{
		if (dict_node->value >= 0)
			pos++;
		else if (dict_node->value < 0)
			neg++;
		i++;
		dict_node = dict_node->next;
	}
	if (i == pos)
		target = l_find_min(head_dict);
	else if (i == neg)
		target = l_find_max(head_dict);
	else if (i != neg && i != pos) // find the min value in pos values
		target = l_find_min_pos(head_dict, pos); //, neg);
	// free_dict(head_dict);
	return (target);
}

int	target_for_max_min(t_dict *head_dict, t_stack *a, t_stack *b)
{
	t_element* min_in_a;
	t_element* max_in_a;
	t_element* min_in_b;
	t_element* max_in_b;

	min_in_a = find_min(a);
	max_in_a = find_max(a);
	min_in_b = find_min(b);
	max_in_b = find_max(b);
	if (head_dict->a_int == min_in_a->data && min_in_a->data < min_in_b->data)
		return (max_in_b->data);
	else if (head_dict->a_int == min_in_a->data && min_in_a->data > min_in_b->data)
		return (min_in_b->data);
	else if (head_dict->a_int == max_in_a->data)
		return (max_in_b->data);
	return (0);
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
	// print_list(head_dict);
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
