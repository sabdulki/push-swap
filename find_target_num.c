/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:39:02 by sabdulki          #+#    #+#             */
/*   Updated: 2024/01/24 19:18:16 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	// printf("\nthe min is: %d\n", min->data);
	return (min->value);
}

t_dict*		init_dictionary()
{
	t_dict *dict = malloc(sizeof(t_dict));
	if (!dict)
		return (NULL);
	dict->next = NULL;
	return (dict);
}

int		find_target(t_stack *a, t_stack *b)
{
	// how to find the closest min number??
	t_element *min_b;
	t_element *max;
	t_element *min;
	t_element *last;
	t_element *tmp_a;
	t_element *tmp_b;

	last = get_last_elem(a);
	max = find_max(a);
	min = find_min(a);
	
	int target;
	
	min_b = find_min(b);
	tmp_a = a->top;
	tmp_b = b->top;
	
	t_dict *dict = init_dictionary();
	t_dict *head_dict;
	head_dict = dict;
	while(tmp_a)
	{
		// check this number -> find target and count steps
		while(tmp_b)
		{
			dict->value = tmp_a->data - tmp_b->data;
			dict->key = tmp_b->data;
			tmp_b = tmp_b->next;
			dict = dict->next;
			printf("dict->value: %d\n", dict->value);
		}
		tmp_a = tmp_a->next;
	}
	target = l_find_min(dict);
	printf("target for one number of 'a' stack is: %d\n", target);
	
	
	
	// if (a->top->data < min_b)
	// {
	// 	push_move(a, b);
	// 	rotate_move(b);
	// }
	// else if ()
	
	// a->top->data 
	return (0); //return число в стаке b на которое встанет число a->top;
}