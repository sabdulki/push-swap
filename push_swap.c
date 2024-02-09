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
	t_stack *b;
	
	a = preparation(argc, argv);
	// print_elements(a);
	if (is_ascending(a))
		return (0);
	b = make_base_for_stack();
	
	// printf("\n\t----- start of sorting -----\t\n");
	sort_2_3(a);

	if (is_ascending(a))
		finish(a, b);
	sort(a, b);
	if (is_ascending(a))
		finish(a, b);
	
	return (0);
}