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

#include "stack.h"

t_element*	find_min(t_stack* stack)
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
	return (min);
}

t_element*	find_max(t_stack *stack)
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
	return (max);
}

t_element	*get_last_elem(t_stack *stack)
{
	t_element *tmp2;
	
	tmp2 = stack->top;
	while(tmp2 && tmp2->next != NULL)
	{
		tmp2 = tmp2->next;
	}
	return (tmp2);
}

bool	is_empty(t_stack* stack)
{
	if (stack->amount == 0)
		return (true);
	return (false);
}

int		is_ascending(t_stack *stack)
{
	t_element *tmp;

	if (!stack || !stack->top || stack->amount == 0)
		return (false);
	if (stack->amount == 1)
		return (true);
	tmp = stack->top->next;
	while (tmp)
	{
		if (tmp->prev && tmp->data < tmp->prev->data)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}