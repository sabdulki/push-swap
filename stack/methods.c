/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:54:43 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/13 17:39:31 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		sort_2_3(t_stack *a)
{
	if (a->amount == 2)
		sort_two(a);
	else if (a->amount == 3)
		sort_three(a, 'a');
	return (0);
}

int	push(t_stack* stack, int num)
{
	t_element *newNum;

	newNum = malloc(sizeof(t_element));
	if (!newNum)
		return (1);
	newNum->data = num;
	newNum->next = stack->top;
	newNum->prev = NULL;
	if (stack->top)
		stack->top->prev = newNum;
    stack->top = newNum;
	stack->amount += 1;
	change_index(stack);
	return (0);
}

int	pop(t_stack* stack)
{
	t_element *tmp;
	
	if (is_empty(stack))
	{
		// printf("you can't pop an element 'cause the stack is empty\n");
		ft_error();
		return (0);
	}
	tmp = stack->top;
	stack->top = stack->top->next;
	if (stack->top)
		stack->top->prev = NULL;
	stack->amount -= 1;
	change_index (stack);
	free(tmp);
	return (0);
}

int	peek(t_stack * stack)
{
	return (stack->top->data);
}

int destroy(t_stack *stack)
{
	if (!stack)
	{
		// printf("there are no stack. return 0.\n");
		return (0);
	}
	if (is_empty(stack))
	{
		// printf("you can't destroy the stack 'cause it is empty\n");
		free(stack);
		return (0);
	}
	while(stack->top)
		pop(stack);
	free(stack);
	return (0);
}
