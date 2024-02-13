/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:07:22 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/13 17:41:58 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	sort_two(t_stack *a)
{
	int tmp;
	t_element *min;

	min = find_min(a);
	if (a->top->data != min->data)
	{
		tmp = a->top->data;
		a->top->data = min->data;
		min->data = tmp;
		printf("sa\n");
	}
	return ;
}

void	sort_three(t_stack *a, char flag)
{
	t_element *max;
	t_element *min;
	t_element *last;

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

void	sort_three_rev(t_stack* b)
{
	t_element *max;
	t_element *min;
	t_element *last;

	last = get_last_elem(b);
	max = find_max(b);
	min = find_min(b);
	
	if (is_decreasing(b))
		return ;
	else if (last->data == max->data && b->top->data != min->data)
	{
		rotate_move(b, 'b');
		rotate_move(b, 'b');
	}
	else if (last->data == max->data && b->top->data == min->data)
	{
		swap_move(b, 'b');
		rev_rotate_move(b, 'b');
	}
	else if (max->data == b->top->data && min->data != last->data)
	{
		rev_rotate_move(b, 'b');
		swap_move(b, 'b');
	}
	else if (last->data == min->data && b->top->data != max->data)
		swap_move(b, 'b');
	else //if (min->data == b->top->data)
		rotate_move(b, 'b');
	return ;
}
