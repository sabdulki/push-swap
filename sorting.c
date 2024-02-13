/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:09:57 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/13 18:47:34 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

void	first_pushes(t_stack *a, t_stack *b, char flag)
{
	int			iter_count;

	iter_count = min(2, a->amount-3);
	while(iter_count != 0)
	{
		push_move(a, b, flag);
		iter_count--;
	}
	return ;
}

void	push_to_a(t_stack *a, t_stack *b, int flag)
{
	t_dict		*moving_num;
	
	while(a->amount != 3)
	{
		if ((peek(b) == find_min(b)->data ) ||  (peek(b) < get_last_elem(b)->data))
			rotate_move(b, 'b');
		if (b->amount == 3)
			sort_three_rev(b);
		moving_num = find_most_profit_num(a, b, flag);
		make_a_move(a, b, moving_num, flag);
	}
	// free(moving_num);
	return ;
}

void	push_to_b(t_stack *a, t_stack *b, int flag)
{
	t_dict		*moving_num;

	while(b->amount != 0)
	{
		moving_num = find_most_profit_num(b, a, flag);
		make_a_move(b, a, moving_num, flag);
		if (peek(a) == find_max(a)->data)
				rotate_move(a, 'a');
	}
	// free(moving_num);
	return ;
}

int	sort(t_stack *a, t_stack *b)
{
	t_element*	a_move;
	char 		flag;

	flag = 'a';
	first_pushes(a, b, flag);
	push_to_a(a, b, flag);
	sort_three(a, flag);
	flag = 'b';
	push_to_b(a, b, flag);
	a_move = find_min(a);
	while(peek(a) != find_min(a)->data)
		target_in_b_is_top(a, a_move, 'a');
	return (0);
}
