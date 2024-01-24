/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:09:57 by sabdulki          #+#    #+#             */
/*   Updated: 2024/01/24 20:09:59 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

void	sort(t_stack *a, t_stack *b)
{
	// int target;
	t_element	*tmp_a;
	int			iter_count;

	iter_count = min(2, a->amount-3);
	tmp_a = a->top;

	// while(tmp_a && (a->amount != a->amount - 2) && a->amount != 3)
	while(tmp_a && iter_count != 0)
	{
		push_move(a, b);
		tmp_a = tmp_a->next;
		iter_count--;
	}
	// while(a->amount != 3)
	// {
		find_target(a, b);
		// tmp_a = tmp_a->next;
	// }
	
}



/*

a -> b

9
1
3	4
5	7

*/