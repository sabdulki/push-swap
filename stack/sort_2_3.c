/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:07:22 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/21 17:53:57 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	sort_2_3(t_stack *a)
{
	if (a->amount == 2)
		sort_two(a);
	else if (a->amount == 3)
		sort_three(a, 'a');
	return (0);
}

void	sort_two(t_stack *a)
{
	int		tmp;
	t_elem	*min;

	min = find_min(a);
	if (a->top->data != min->data)
	{
		tmp = a->top->data;
		a->top->data = min->data;
		min->data = tmp;
		ft_printf("sa\n");
	}
	return ;
}

void	sort_three(t_stack *a, char flag)
{
	t_elem	*max;
	t_elem	*min;
	t_elem	*last;

	last = get_last_elem(a);
	max = find_max(a);
	min = find_min(a);
	if (max->data == last->data && min->data != a->top->data)
		swap_move(a, flag);
	else if (a->top->data == max->data && min->data == last->data)
	{
		rotate_move(a, flag);
		swap_move(a, flag);
	}
	else if (max->data == a->top->data)
		rotate_move(a, flag);
	else if (min->data == last->data)
		rev_rotate_move(a, flag);
	else if (min->data == a->top->data && max->data != last->data)
	{
		rotate_move(a, flag);
		swap_move(a, flag);
		rev_rotate_move(a, flag);
	}
	return ;
}

void	sort_three_rev(t_stack *b)
{
	t_elem	*last;
	t_elem	*min;

	last = get_last_elem(b);
	min = find_min(b);
	if (is_decreasing(b))
		return ;
	else if (last->data == find_max(b)->data && b->top->data != min->data)
		rev_rotate_move(b, 'b');
	else if (last->data == find_max(b)->data && b->top->data == min->data)
	{
		swap_move(b, 'b');
		rev_rotate_move(b, 'b');
	}
	else if (find_max(b)->data == b->top->data && min->data != last->data)
	{
		rev_rotate_move(b, 'b');
		swap_move(b, 'b');
	}
	else if (last->data == min->data && b->top->data != find_max(b)->data)
		swap_move(b, 'b');
	else
		rotate_move(b, 'b');
	return ;
}
