/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:35:43 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/13 18:21:14 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		count_steps(t_stack *a, t_stack *b, t_element *tmp_a,  t_element *target)
{
	int	steps_a;
	int	steps_b;
	int	all_steps;

	steps_a = 0;
	steps_b = 0;
	steps_a = count_a_steps(a, tmp_a);
	steps_b = count_b_steps(b, target);
	all_steps = steps_a + steps_b + 1;
	return (all_steps);
}

int		count_a_steps(t_stack *a, t_element* tmp_a)
{
	int	steps_a;
	int	median;
	
	steps_a = 0;
	median = a->amount / 2;
	if (tmp_a->index <= median)
		steps_a = tmp_a->index - 1;
	else if(tmp_a->index > median)
		steps_a = a->amount - tmp_a->index + 1;
	return (steps_a);
}

int		count_b_steps(t_stack *b, t_element *target)
{
	t_element	*tmp_b;
	int			steps_b;
	int			median;

	tmp_b = find_target_index(b, target);
	median = b->amount / 2;
	steps_b = 0;
	if (tmp_b->index <= median)
		steps_b = tmp_b->index - 1;
	else if (tmp_b->index > median)
		steps_b = b->amount - tmp_b->index + 1;
	return (steps_b);
}

t_element	*find_target_index(t_stack *b, t_element *target)
{
	t_element *tmp;
	
	tmp = b->top;
	while(tmp)
	{
		if (tmp->data == target->data)
			return (tmp);
		tmp = tmp->next;
	}
	printf("haven't found element with the same number. Return head of stack");
	return(b->top);
}
