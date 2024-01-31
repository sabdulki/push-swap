/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:09:57 by sabdulki          #+#    #+#             */
/*   Updated: 2024/01/31 20:07:27 by sabdulki         ###   ########.fr       */
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
	int			i = 1;
	t_dict		*moving_num;
	iter_count = min(2, a->amount-3);
	tmp_a = a->top;

	// while(tmp_a && (a->amount != a->amount - 2) && a->amount != 3)
	while(tmp_a && iter_count != 0)
	{
		push_move(a, b);
		tmp_a = tmp_a->next;
		iter_count--;
	}
	// moving_num = find_most_profit_num(a, b);
	while(a->amount != 3)
	{
		printf("\n------%d new call of finding profit num ------\n", i);
		print_elements(b);
		moving_num = find_most_profit_num(a, b);
		make_a_move(a, b, moving_num);
		// main_process(a, b); DONE
		//count steps
		//compare steps (which number is chepest to move)
		//make_a_move();
		//durng the push_move a->amount =-1 
		// a->amount =-1;
		i++;
	}
	// sort_three(a);
	
	
}

/*

a -> b

9
1
3	4
5	7

*/