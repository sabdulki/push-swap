/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_a_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:23:54 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/09 18:49:13 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_a_move(t_stack *a, t_stack *b, t_dict *moving_num, char flag)
{
	// t_element* min_b;
	
	// printf("a: %d, b: %d, value: %d\n", moving_num->a_int, moving_num->b_int, moving_num->value);
	// printf("in-make-a-move\n");
	move_in_a(a, moving_num, flag);
		printf("'B': ");
		print_elements(a);
	move_in_b(b, moving_num, flag);
		printf("\n'A' after SORTing: ");
		print_elements(b);
	push_move(a, b, flag);
		printf("\n'A' after PUSHing: ");
		print_elements(b);
		// print_elements(a);
		// print_elements(b);
	// min_b = find_min(b);
	// if (peek(b) == min_b->data)
	// 	rotate_move(b);
	// additional move if needed
	// for example if we get the minimum num into b and it's the first num.
	// i should place it to the end by rotate_move
	
}

void	move_in_a(t_stack* a, t_dict *moving_num, char flag)
{
	printf("in-move-a\n");
	int median;
	int				a_move_data;
	t_element* a_move;

	// printf("%c->amount: %d\n", flag, a->amount);
	if (a->amount == 1)	
			return ;

	median = a->amount / 2;
	a_move = find_position_in_a(a, moving_num);
	// printf("'%d' index: %d\n", a_move->data, a_move->index);
	if (a_move->data == peek(a))
		return ; //ready to push in stack b;
	else if (a_move->index <= median)
	{
		a_move_data = a_move->data;
		while(a_move_data != peek(a))
		{
		 	rotate_move(a, flag);
		}
	}
	else if (a_move->index > median)
	{
		a_move_data = a_move->data;
		while(a_move_data != peek(a))
		{
		 	rev_rotate_move(a, flag);
		}
	}
	// print_elem_index(a);
	return ;
}

void	move_in_b(t_stack* b,  t_dict *moving_num, char flag)
{
	printf("\n'A': ");
	print_elements(b);
	t_element*		b_move;
	int				b_move_data;
	int				median;

	// printf("%c->amount: %d\n", flag, b->amount);
	if (b->amount == 1)
		return ;

	median = b->amount / 2;
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
	
	// printf("b_move: %d\n", b_move->data);
	// if (is_descending == true && b_move->data == peek(b))
	// {
	// 	//move items inside if it's needed
	// 	return ;
	// }
	if (flag == 'a')
		flag = 'b';
	else if (flag == 'b')
		flag = 'a';
	if (b_move->data == peek(b))
	{
		// printf("here-in-b-peek\n");
		return ;
	}
	else if (b_move->index <= median)
	{
		b_move_data = b_move->data;
		while(b_move_data != peek(b))
		{
		 	rotate_move(b, flag);
		}
	}
	else if (b_move->index > median)
	{
		b_move_data = b_move->data;
		while(b_move_data != peek(b))
		{
			// printf("b_move: %d\n", b_move->data);
			// printf(" move in b rev rotate ");
		 	rev_rotate_move(b, flag);
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

int		is_decreasing(t_stack *stack)
{
	t_element *tmp;
	// t_element *max;
	t_element *last;

	tmp = stack->top;
	// max = stack->top;
	last = get_last_elem(stack);
	while(tmp && last->prev)
	{
		if (last->data > last->prev->data)
		{
			// printf("not descending\n");
			return (false); // 0
		}
		last = last->prev;
		tmp = tmp->next;
	}
	// printf("\nthe elements of this stack are in descending order!\n");
	return (true); // 1
}