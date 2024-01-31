/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:54:43 by sabdulki          #+#    #+#             */
/*   Updated: 2024/01/31 19:49:58 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		determination(t_stack *a)
{
	if (a->amount == 2)
		sort_two(a);
	else if (a->amount == 3)
		sort_three(a);
	else if (a->amount > 3)
		printf("\tready to sort. stack has more tham 3 numbers\n");
	return (0);
}

int	push(t_stack* stack, int num) //, int index)
{
	t_element *newNum;

	newNum = malloc(sizeof(t_element));
	if (!newNum)
		return (0);
	newNum->data = num;
	// if (!stack->top)
	// 	newNum->index = 0;
	// newNum->index = 1;
	newNum->next = stack->top;
	newNum->prev = NULL;
	
	if (stack->top)
		stack->top->prev = newNum;
		
	// stack->top->index = index ++;
    stack->top = newNum;
	// stack->top->prev->index = index++;
	
	stack->amount += 1;
	
	// printf("the new top is: %d\n", stack->top->data);
	change_index(stack);
	return (stack->amount);
}

int	pop(t_stack* stack)
{
	if (is_empty(stack))
	{
		printf("you can't pop an element 'cause the stack is empty\n");
		return (0);
	}
	t_element *tmp;
	tmp = stack->top;
	stack->top = stack->top->next;
	if (stack->top)
		stack->top->prev = NULL;
	stack->amount -= 1;
	change_index (stack); //->top);
	free(tmp);
	
	if (stack->top)
	{
		printf("new top after popping is: %d\n", stack->top->data);
		printf("amount: %d\n", stack->amount);
	}
	return (0);
}

int	peek(t_stack * stack)
{
	printf("the topmost elem is %d\n", stack->top->data);
	return (stack->top->data);
}

int destroy(t_stack *stack)
{
	if (!stack)
		return (0);
	if (is_empty(stack))
	{
		printf("you can't destroy the stack 'cause it is empty\n");
		return (0);
	}
	while(stack->top)
		pop(stack);
	free(stack);
	
	printf("the stack has been sucsessfully destroyed!");
	return (0);
}
