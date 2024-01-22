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

// void	for_two(t_stack *a)
// {
// 	t_element *tmp = NULL;
// 	t_element *min;

// 	min = find_min(a);
// 	if (a->top->data != min->data)
// 	{
// 		tmp = a->top;
// 		a->top= min;
// 		min = tmp;
// 	}
// 	printf("sa\n");
// 	print_elements(a);
// }

void	for_two(t_stack *a) // sa, sb
{
	int tmp;
	t_element *min;

	min = find_min(a);
	if (a->top->data != min->data)
	{
		tmp = a->top->data;
		a->top->data = min->data;
		min->data = tmp;
		printf("sa\n");
	}
	else
		printf("sa didn't need\n");
	print_elements(a);
}

// pop, destroy, 