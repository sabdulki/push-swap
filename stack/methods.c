/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:54:43 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/15 15:59:36 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	push(t_stack *stack, int num)
{
	t_element	*new_num;

	new_num = malloc(sizeof(t_element));
	if (!new_num)
		return (1);
	new_num->data = num;
	new_num->next = stack->top;
	new_num->prev = NULL;
	if (stack->top)
		stack->top->prev = new_num;
	stack->top = new_num;
	stack->amount += 1;
	change_index(stack);
	return (0);
}

int	pop(t_stack *stack)
{
	t_element	*tmp;

	if (is_empty(stack))
	{
		// printf("you can't pop an element 'cause the stack is empty\n");
		return (1);
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

int	peek(t_stack *stack)
{
	return (stack->top->data);
}

t_element	*get_last_elem(t_stack *stack)
{
	t_element	*tmp2;

	tmp2 = stack->top;
	while (tmp2 && tmp2->next != NULL)
	{
		tmp2 = tmp2->next;
	}
	return (tmp2);
}

int	destroy(t_stack *stack)
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
	while (stack->top)
		pop(stack);
	free(stack);
	return (0);
}
