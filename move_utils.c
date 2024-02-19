/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:04:51 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/19 21:14:02 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*find_position_in_a(t_stack *a, t_dict *moving_num)
{
	t_element	*tmp;

	tmp = a->top;
	while (tmp)
	{
		if (tmp->data == moving_num->a_int)
			return (tmp);
		tmp = tmp->next;
	}
	// printf("haven't found element with the same number. Return head of stack\n");
	return (a->top);
}

t_element	*find_position_in_b(t_stack *b, t_dict *moving_num)
{
	t_element	*tmp;

	tmp = b->top;
	while (tmp)
	{
		if (tmp->data == moving_num->b_int)
			return (tmp);
		tmp = tmp->next;
	}
	// printf("haven't found element with the same number. Return head of stack\n");
	return (b->top);
}
