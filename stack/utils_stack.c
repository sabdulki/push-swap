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

t_element	*find_min(t_stack *stack)
{
	t_element	*tmp;
	t_element	*min;

	tmp = stack->top;
	min = stack->top;
	while (tmp)
	{
		if (tmp->data < min->data)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_element	*find_max(t_stack *stack)
{
	t_element	*tmp;
	t_element	*max;

	tmp = stack->top;
	max = stack->top;
	while (tmp)
	{
		if (tmp->data > max->data)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

bool	is_empty(t_stack *stack)
{
	if (stack->amount == 0)
		return (true);
	return (false);
}

int	is_ascending(t_stack *stack)
{
	t_element	*tmp;

	if (!stack || !stack->top || stack->amount == 0)
		return (false);
	tmp = stack->top->next;
	while (tmp)
	{
		if (tmp->prev && tmp->data < tmp->prev->data)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

int	is_decreasing(t_stack *stack)
{
	t_element	*tmp;
	t_element	*last;

	tmp = stack->top;
	last = get_last_elem(stack);
	while (tmp && last->prev)
	{
		if (last->data > last->prev->data)
			return (false);
		last = last->prev;
		tmp = tmp->next;
	}
	return (true);
}
