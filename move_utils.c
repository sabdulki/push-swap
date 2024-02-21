/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:04:51 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/21 14:40:34 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*find_position_in_a(t_stack *a, t_dict *moving_num)
{
	t_elem	*tmp;

	tmp = a->top;
	while (tmp)
	{
		if (tmp->data == moving_num->a_int)
			return (tmp);
		tmp = tmp->next;
	}
	return (a->top);
}

t_elem	*find_position_in_b(t_stack *b, t_dict *moving_num)
{
	t_elem	*tmp;

	tmp = b->top;
	while (tmp)
	{
		if (tmp->data == moving_num->b_int)
			return (tmp);
		tmp = tmp->next;
	}
	return (b->top);
}
