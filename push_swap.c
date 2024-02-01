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
	// stack->top->index = 0;
	stack->amount = 0;
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
	t_stack *a;
	t_stack *a_prep; 
	t_stack *b;
	
	a_prep = preparation(argc, argv);
	// a = copy_stack(a_prep);
	// change_index(a);
	b = make_base_for_stack();

	// is_descending(a);

	if (is_ascending(a))
		return (0);
	
	print_elem_index(a);
	printf("\n\t----- start of sorting -----\t\n");
	determination(a);
	sort(a, b);

	// rev_rotate_move(a);
	// rotate_move(a);
	// get_last_elem(a);
	// pop(a);
	// destroy(a);


	// find_max(a);
	// find_min(a);

	// swap_move(a);
	// push_move(a, b);
	

	
	// printf("amount a: %d\n", a->amount);
	// printf("amount b: %d\n", b->amount);
	
	// for_two(a);
	// printf("min: %d\n", min->data);
}