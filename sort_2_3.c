/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:07:22 by sabdulki          #+#    #+#             */
/*   Updated: 2024/01/24 17:08:50 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a) // sa, sb
{
	int tmp;
	t_element *min;

	min = find_min(a);
	if (a->top->data != min->data)
	{
		tmp = a->top->data;
		a->top->data = min->data;
		min->data = tmp;
		printf("--- sa ---\n");
	}
	else
		printf("sa didn't need\n");
	print_elements(a);
}

void	sort_three(t_stack *a)
{
	t_element *max;
	t_element *min;
	t_element *last;

	last = get_last_elem(a);
	max = find_max(a);
	min = find_min(a);

	if (max->data == last->data && min->data != a->top->data)
		swap_move(a);
	else if (a->top->data == max->data && min->data == last->data)
	{
		rotate_move(a);
		swap_move(a);
	}
	else if (max->data == a->top->data)
		rotate_move(a);
	else if (min->data == last->data)
		rev_rotate_move(a);
	printf("alg for 3 elem done\n");
}
