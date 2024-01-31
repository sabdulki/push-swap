/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_a_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:23:54 by sabdulki          #+#    #+#             */
/*   Updated: 2024/01/31 18:51:06 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_a_move(t_stack *a, t_stack *b, t_dict *moving_num)
{
	move_in_a(a, moving_num); //push_move anyway
		print_elements(a);
	move_in_b(b, moving_num);
		print_elements(b);
	push_move(a, b);
		print_elements(a);
		print_elements(b);
	// additional move if needed
	// for example if we get the minimum num into b and it's the first num.
	// i should place it to the end by rotate_move
	
}

void	move_in_a(t_stack* a, t_dict *moving_num)
{
	int median;
	int				a_move_data;
	t_element* a_move;

	median = a->amount / 2;
	a_move = find_position_in_a(a, moving_num);
	printf("'%d' index: %d\n", a_move->data, a_move->index);
	if (a_move->data == peek(a))
		return ; //ready to push in stack b;
	else if (a_move->index <= median)
	{
		a_move_data = a_move->data;
		while(a_move_data != peek(a))
		{
		 	rotate_move(a);
		}
	}
	else if (a_move->index > median)
	{
		a_move_data = a_move->data;
		while(a_move_data != peek(a))
		{
		 	rev_rotate_move(a);
		}
	}
	print_elem_index(a);
	return ;
}

void	move_in_b(t_stack* b,  t_dict *moving_num)
{
	t_element*		b_move;
	int				b_move_data;
	int				median;

	median = b->amount / 2;
	b_move = find_position_in_b(b, moving_num);
	// printf("b_move: %d\n", b_move->data);
	// if (is_descending == true && b_move->data == peek(b))
	// {
	// 	//move items inside if it's needed
	// 	return ;
	// }
	if (b_move->data == peek(b))
	{
		printf("here-in-b-peek\n");
		return ;
	}
	else if (b_move->index <= median)
	{
		b_move_data = b_move->data;
		while(b_move_data != peek(b))
		{
		 	rotate_move(b);
		}
	}
	else if (b_move->index > median)
	{
		b_move_data = b_move->data;
		while(b_move_data != peek(b))
		{
			// printf("b_move: %d\n", b_move->data);
		 	rev_rotate_move(b);
		}
	}
	
	// if (b_move->data != peek(b))
	// {
	// 	while(b_move->data != peek(b))
	// 		rotate_move(b);
	// }
	// check if it's decending
	// true? move the num
	// false? make it descending first

	return ;
}

t_element* find_position_in_a(t_stack* a, t_dict *moving_num)
{
	t_element* tmp;

	tmp = a->top;
	while(tmp)
	{
		if (tmp->data == moving_num->a_int)
			return (tmp);
		tmp = tmp->next;
	}
	printf("haven't found element with the same number. Return head of stack\n");
	return(a->top);
}

t_element* find_position_in_b(t_stack* b, t_dict *moving_num)
{
	t_element* tmp;

	tmp = b->top;
	while(tmp)
	{
		if (tmp->data == moving_num->b_int)
			return (tmp);
		tmp = tmp->next;
	}
	printf("haven't found element with the same number. Return head of stack\n");
	return(b->top);
}

bool	is_descending(t_stack *stack)
{
	t_element *tmp;
	t_element *max;
	t_element *last;

	tmp = stack->top;
	max = stack->top;
	last = get_last_elem(stack);
	while(tmp && last->prev)
	{
		if (last->data > last->prev->data)
		{
			printf("not descending\n");
			return (false); // 0
		}
		last = last->prev;
		tmp = tmp->next;
	}
	printf("\nthe elements of this stack are in descending order!\n");
	return (true); // 1
}