/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:09:57 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/24 18:36:06 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

int	first_pushes(t_stack *a, t_stack *b, char flag)
{
	int	iter_count;

	iter_count = min(2, a->amount - 3);
	while (iter_count != 0)
	{
		if (push_move(a, b, flag) == 1)
			return (1);
		iter_count--;
	}
	return (0);
}

int	push_to_a(t_stack *a, t_stack *b, int flag)
{
	t_dict	*moving_num;
	t_dict	*step_h_d;
	t_elem	*last;

	last = get_last_elem(b);
	while (a->amount != 3)
	{
		if ((peek(b) == find_min(b)->data) || (peek(b) < last->data))
			rotate_move(b, 'b');
		if (b->amount == 3)
			sort_three_rev(b);
		step_h_d = find_most_profit_num(a, b, flag);
		if (!step_h_d)
			return (1);
		moving_num = step_find_min(step_h_d);
		if (make_a_move(a, b, moving_num, flag) == 1)
			return (1);
		free_dict(step_h_d);
	}
	return (0);
}

int	push_to_b(t_stack *a, t_stack *b, int flag)
{
	t_dict	*moving_num;
	t_dict	*step_h_d;

	while (b->amount != 0)
	{
		step_h_d = find_most_profit_num(b, a, flag);
		if (!step_h_d)
			return (1);
		moving_num = step_find_min(step_h_d);
		if (make_a_move(b, a, moving_num, flag) == 1)
			return (1);
		if (peek(a) == find_max(a)->data)
			rotate_move(a, 'a');
		free_dict(moving_num);
	}
	return (0);
}

int	sort(t_stack *a, t_stack *b)
{
	t_elem	*a_move;
	char	flag;

	flag = 'a';
	if (first_pushes(a, b, flag) == 1)
		return (1);
	if (push_to_a(a, b, flag) == 1)
		return (1);
	sort_three(a, flag);
	flag = 'b';
	if (push_to_b(a, b, flag) == 1)
		return (1);
	a_move = find_min(a);
	while (peek(a) != find_min(a)->data)
		target_in_b_is_top(a, a_move, 'a');
	return (0);
}
