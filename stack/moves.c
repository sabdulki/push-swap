/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:57:26 by sabdulki          #+#    #+#             */
/*   Updated: 2024/01/30 20:48:11 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap_move(t_stack *stack)
{
	t_element *tmp;

	tmp = stack->top; // 1
	stack->top = stack->top->next; // top = 2. aaddres of 2 node equal to top
	stack->top->prev = NULL; // 2 -> 1 --> 2 -/-> 1
	stack->top->index = 1;
	tmp->prev = stack->top;
	tmp->next = stack->top->next; // 1 -> 3
	stack->top->next = tmp;
	stack->top->next->index = 2;
	printf("\n---sa done---\n");
	
	print_elem_index(stack);
}

void	push_move(t_stack *a, t_stack *b)
{
	//it's part from pop function. how can i change this code
	// using pop func without deleteing information about temp
	// inside the func? and do smth like 
	// pop(a);
	// push (b);
	t_element *tmp;

	tmp = a->top;
	a->top = a->top->next;
	if (a->top)
		a->top->prev = NULL;
	a->amount -= 1;
	push(b, tmp->data);
	change_index(a);

	printf("stack a:");
	print_elem_index(a);
	printf("stack b:");
	print_elem_index(b);
	printf("\n--- push_move done ---\n");
}

void	rotate_move(t_stack *stack)
{
	t_element	*tmp;
	int			first_int;
	// int			index;
	
	// index = 1;
	first_int = stack->top->data;
	tmp = stack->top;
	while(tmp && tmp->next)
	{
		tmp->data = tmp->next->data;
		tmp = tmp->next;
		// index++;
	}
	tmp->data = first_int;
	// tmp->index = index;
	change_index(stack);
	printf("\n--- rotate is done ---\n");
	print_elem_index(stack);
}

void	rev_rotate_move(t_stack *stack)
{
	t_element	*last;
	int			last_int;
	
	last = get_last_elem(stack);
	last_int = last->data;
	while(last && last->prev != NULL)
	{
		last->data = last->prev->data;
		last = last->prev;
	}
	stack->top->data = last_int;
	change_index(stack);
	printf("\n--- reverse rotate is done ---\n");
	print_elem_index(stack);
}