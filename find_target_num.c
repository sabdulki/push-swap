/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:51:56 by sabdulki          #+#    #+#             */
/*   Updated: 2024/01/25 20:00:30 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	main_process (t_stack *a, t_stack *b) 
{
	t_element *tmp_a;
	t_element *tmp_b;
	t_dict *dict;
	int target;
	tmp_a = a->top;
	tmp_b = b->top;

	while(tmp_a)
	{
		dict = find_value(tmp_a->data, b);
		target = find_target(dict);
		printf("target for '%d' number of 'a' stack is: %d\n", tmp_a->data, target);
		// я нашла число, к которому пойдет первое число из стака а.
		// теперь мне надо посчитать количество шагов для первого числа из стака а до его таргета.
		// a function to do this
		tmp_a = tmp_a->next;
	}
}
int		find_target(t_dict* head_dict) // находит target-числло из b  для ОДНОГО числа из стака а
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
	
	// если no_dict->key = самое маленькое число стака а, то его target = l_find_max;
	// если no_dict->key = самое большое число стака а, то его target = l_find_min;
	while(dict_node)
	{
		if (dict_node->value >= 0)
			pos++;
		else if (dict_node->value < 0)
			neg++;
		i++;
		dict_node = dict_node->next;
	}
	if (i == pos) //all values of dict are posistive
		target = l_find_min(dict_node);
	else if (i == neg || (i != neg && i != pos)) // all values of dict are negative
		target = l_find_max(dict_node); // values are both positive and negative
	return (target);
}

int		l_find_min(t_dict *dict)
{
	t_dict *tmp;
	t_dict *min;

	tmp = dict;
	min = dict;
	while(tmp)
	{
		if (tmp->value < min->value)
			min = tmp;
		tmp = tmp->next;
	}
	printf("\nthe min is: %d\n", min->key);
	return (min->key);
}

int		l_find_max(t_dict* dict)
{
	t_dict *tmp;
	t_dict *max;

	tmp = dict;
	max = dict;
	while(tmp)
	{
		if (tmp->value > max->value)
			max = tmp;
		tmp = tmp->next;
	}
	printf("\nthe max is: %d\n", max->key);
	return (max->key);
}

t_dict*	find_value(int num_a, t_stack *b) // находит все value для ОДНОГО числа из стака а
{
	t_element *tmp_b;
	t_dict *head_dict;
	t_dict *dict_node;

	head_dict = create_dictinary(b);
	dict_node = head_dict;
	tmp_b = b->top;

	// работать только с одниим числом из стака а
	dict_node->key = num_a; // у list!!!!
	while(tmp_b)
	{
		dict_node->value = num_a - tmp_b->data;
		dict_node = dict_node->next;
	}
	return (head_dict); // или все же dict_node??
}

// определяет из всех value что я получила
