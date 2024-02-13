/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:57:26 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/13 17:41:33 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap_move(t_stack *stack, char flag)
{
	t_element *tmp;

	tmp = stack->top;
	stack->top = stack->top->next;
	stack->top->prev = NULL;
	stack->top->index = 1;
	tmp->prev = stack->top;
	tmp->next = stack->top->next;
	tmp->next->prev = tmp;
	stack->top->next = tmp;
	stack->top->next->index = 2;

	if (flag == 'a')
		printf("sa\n");
	else if (flag == 'b')
		printf("sb\n");
	return ;
}

void	push_move(t_stack *a, t_stack *b, char flag)
{
	int	tmp_num;

	if (!a || a->amount == 0)
		return ;
	tmp_num = a->top->data;
	pop(a);
	push(b, tmp_num);
	change_index(a);
	if (flag == 'a')
		printf("pb\n");
	else if (flag == 'b')
		printf("pa\n");
	return ;
}

void	rotate_move(t_stack *stack, char flag)
{
	t_element	*tmp;
	int			first_int;
	
	first_int = stack->top->data;
	tmp = stack->top;
	while(tmp && tmp->next)
	{
		tmp->data = tmp->next->data;
		tmp = tmp->next;
	}
	tmp->data = first_int;
	change_index(stack);
	if (flag == 'a')
		printf("ra\n");
	else if (flag == 'b')
		printf("rb\n");
	return ;
}

void	rev_rotate_move(t_stack *stack, char flag)
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
	if (flag == 'a')
		printf("rra\n");
	else if (flag == 'b')
		printf("rrb\n");
	return ;
}