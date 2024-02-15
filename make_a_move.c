/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_a_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:23:54 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/15 15:47:51 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_a_move(t_stack *a, t_stack *b, t_dict *moving_num, char flag)
{
	move_in_a(a, moving_num, flag);
	move_in_b(b, moving_num, flag);
	return (push_move(a, b, flag));
}

void	move_in_a(t_stack* a, t_dict *moving_num, char flag)
{
	int			median;
	int			a_move_data;
	t_element*	a_move;

	if (a->amount == 1)	
			return ;
	median = a->amount / 2;
	a_move = find_position_in_a(a, moving_num);
	if (a_move->data == peek(a))
		return ;
	else if (a_move->index <= median)
	{
		a_move_data = a_move->data;
		while(a_move_data != peek(a))
		 	rotate_move(a, flag);
	}
	else if (a_move->index > median)
	{
		a_move_data = a_move->data;
		while(a_move_data != peek(a))
		 	rev_rotate_move(a, flag);
	}
	return ;
}

void	move_in_b(t_stack* b,  t_dict *moving_num, char flag)
{
	t_element*	b_move;

	if (b->amount == 1)
		return ;
	b_move = find_position_in_b(b, moving_num);
	if (flag == 'a')
	{
		if (moving_num->a_int < find_min(b)->data && find_min(b)->data  == get_last_elem(b)->data)
			return ;
	}
	else if (flag == 'b')
	{
		if (moving_num->a_int > find_max(b)->data && find_max(b)->data  == get_last_elem(b)->data)
			return ;
	}
	if (flag == 'a')
		flag = 'b';
	else if (flag == 'b')
		flag = 'a';
	target_in_b_is_top(b, b_move, flag);
	return ;
}

void	target_in_b_is_top(t_stack *b, t_element* b_move, char flag)
{
	int b_move_data;
	int median;

	median = b->amount / 2;
	if (b_move->data == peek(b))
		return ;
	else if (b_move->index <= median)
	{
		b_move_data = b_move->data;
		while(b_move_data != peek(b))
		 	rotate_move(b, flag);
	}
	else if (b_move->index > median)
	{
		b_move_data = b_move->data;
		while(b_move_data != peek(b))
		 	rev_rotate_move(b, flag);
	}
	return ;
}
