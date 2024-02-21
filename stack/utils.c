/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:18:49 by sabdulki          #+#    #+#             */
/*   Updated: 2023/10/04 17:26:36 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	print_elements(t_stack *stack)
{
	t_elem	*head;

	if (is_empty(stack))
		return ;
	head = stack->top;
	while (head)
	{
		ft_printf("%d ", head->data);
		head = head->next;
	}
	return ;
}

void	change_index(t_stack *stack)
{
	t_elem	*tmp_top;
	int		index;

	tmp_top = stack->top;
	index = 1;
	while (tmp_top)
	{
		tmp_top->index = index++;
		tmp_top = tmp_top->next;
	}
	return ;
}

void	finish(t_stack *a, t_stack *b)
{
	if (b && !is_empty(b))
	{
		while (b->amount != 0)
			pop(b);
	}
	destroy(a);
	destroy(b);
}
