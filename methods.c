/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:54:43 by sabdulki          #+#    #+#             */
/*   Updated: 2024/01/22 18:13:07 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_empty(t_stack* stack)
{
	if (stack->amount == 0)
		return (true); // 1
	return (false); // 0 
}

int	push(t_stack* stack, int num) //, int amount)
{
	t_element *newNum;

	newNum = malloc(sizeof(t_element));
	if (!newNum)
		return (0);
	newNum->data = num;
	newNum->next = stack->top;
	newNum->prev = NULL;
	if (stack->top)
		stack->top->prev = newNum;
    stack->top = newNum;
	stack->amount += 1;
	printf("the new top is: %d\n", stack->top->data);
	return (stack->amount);
}

int	pop(t_stack* stack)
{
	if (is_empty(stack) == true)
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
	free(tmp);
	
	if (stack->top)
		printf("new top after popping is: %d\n", stack->top->data);
	return (0);
}

int	peek(t_stack * stack)
{
	printf("the topmost elem is %d\n", stack->top->data);
	return (stack->top->data);
}

t_element *get_last_elem(t_stack *stack)
{
	t_element *tmp2;
	
	tmp2 = stack->top;
	while(tmp2 && tmp2->next != NULL)
	{
		tmp2 = tmp2->next;
	}
	printf("the last elem of this stack is: %d\n", tmp2->data);
	return (tmp2);
}

int destroy(t_stack *stack)
{
	if (!stack)
		return (0);
	if (is_empty(stack) == true)
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

