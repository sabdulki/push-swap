/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:35:40 by sabdulki          #+#    #+#             */
/*   Updated: 2023/10/04 18:52:03 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element* find_min(t_stack* stack)
{
	t_element *tmp;
	t_element *min;

	tmp = stack->top;
	min = stack->top;
	while(tmp)
	{
		if (tmp->data < min->data)
			min = tmp;
		tmp = tmp->next;
	}
	// printf("\nthe min is: %d\n", min->data);
	return (min);
}

t_element* find_max(t_stack *stack)
{
	t_element *tmp;
	t_element *max;

	tmp = stack->top;
	max = stack->top;
	while(tmp)
	{
		if (tmp->data > max->data)
			max = tmp;
		tmp = tmp->next;
	}
	// printf("\nthe max is: %d\n", max->data);
	return (max);
}

t_element *get_last_elem(t_stack *stack)
{
	t_element *tmp2;
	
	tmp2 = stack->top;
	while(tmp2 && tmp2->next != NULL)
	{
		tmp2 = tmp2->next;
	}
	printf("the last elem of this stack is: %d\n", tmp2->data);
	return (tmp2);
}

bool	is_empty(t_stack* stack)
{
	if (stack->amount == 0)
		return (true); // 1
	return (false); // 0 
}

int		is_ascending(t_stack *stack)
{
	t_element *tmp;
	t_element *min;

	tmp = stack->top;
	min = stack->top;
	while(tmp)
	{
		if (tmp->data < min->data)
		{
			return (false); // 0
		}
		tmp = tmp->next;
	}
	printf("\nthe elements of this stack are in ascending oreder!\n");
	return (true); // 1
}
