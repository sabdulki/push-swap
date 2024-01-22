/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:55:32 by sabdulki          #+#    #+#             */
/*   Updated: 2023/10/04 20:15:01 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *make_base_for_stack()
{
	t_stack *stack = malloc(sizeof(t_stack));
	stack->top = NULL;
	return (stack);
}

t_stack *preparation(int argc, char **argv)
{
	t_stack *stack; 
	stack = make_base_for_stack();
	parsing(argc, argv, stack);
	return(stack);
}

int main (int argc, char **argv)
{
	if (argc <= 2)
		return (0);
	
	// if (argc == 2)
		// call function

	t_stack *a; 
	t_stack *b;
	// t_element* min;
	
	a = preparation(argc, argv);
	b = make_base_for_stack();

	// rev_rotate_move(a);
	// rotate_move(a);
	// get_last_elem(a);
	// pop(a);
	// destroy(a);


	// find_max(a);
	// find_min(a);

	// swap_move(a);
	// push_move(a, b);
	

	
	// printf("the new top is: %d\n", a->top->data);
	
	// for_two(a);
	// printf("min: %d\n", min->data);
}