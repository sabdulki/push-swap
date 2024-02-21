/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:57:26 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/21 17:53:18 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap_move(t_stack *stack, char flag)
{
	t_elem	*tmp;

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
		ft_printf("sa\n");
	else if (flag == 'b')
		ft_printf("sb\n");
	return ;
}

int	push_move(t_stack *a, t_stack *b, char flag)
{
	int	tmp_num;

	if (!a || a->amount == 0)
		return (1);
	tmp_num = a->top->data;
	if (pop(a) == 1)
		return (1);
	if (push(b, tmp_num) == 1)
		return (1);
	change_index(a);
	if (flag == 'a')
		ft_printf("pb\n");
	else if (flag == 'b')
		ft_printf("pa\n");
	return (0);
}

void	rotate_move(t_stack *stack, char flag)
{
	t_elem	*tmp;
	int		first_int;

	first_int = stack->top->data;
	tmp = stack->top;
	while (tmp && tmp->next)
	{
		tmp->data = tmp->next->data;
		tmp = tmp->next;
	}
	tmp->data = first_int;
	change_index(stack);
	if (flag == 'a')
		ft_printf("ra\n");
	else if (flag == 'b')
		ft_printf("rb\n");
	return ;
}

void	rev_rotate_move(t_stack *stack, char flag)
{
	t_elem	*last;
	int		last_int;

	last = get_last_elem(stack);
	last_int = last->data;
	while (last && last->prev != NULL)
	{
		last->data = last->prev->data;
		last = last->prev;
	}
	stack->top->data = last_int;
	change_index(stack);
	if (flag == 'a')
		ft_printf("rra\n");
	else if (flag == 'b')
		ft_printf("rrb\n");
	return ;
}
