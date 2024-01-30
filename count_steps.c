/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:35:43 by sabdulki          #+#    #+#             */
/*   Updated: 2024/01/30 21:03:53 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
in this file I'll count how many steps my algoritm will do
to reach target num from stack 'b'
example:
a	b

9	
1	
3	4
5	7

for '9' target num is '4' 
I got this target num fom previos functions.
how many moves would '9' alg do to reacch '4'
*/ 

/* return how many steps need ONE number to push into b */
// i'll save all steps of all numbers in another function
int count_steps(t_stack *a, t_stack *b, t_element *tmp_a, int target)
{
	int steps_a;
	int steps_b;
	int all_steps;
	int median;

	steps_a = 0;
	steps_a = 0;
	all_steps = 0;
	median = a->amount / 2;

	if (tmp_a->data == peek(a))
		steps_a += 0;
	else
		// function which wiil move number in 'a' to the top of 'a'
		steps_a = count_a_steps(a, tmp_a, median);
	
	if (target == peek(b))
		steps_b += 0;
	// else
		// function which wiil move number in 'b' to the top of 'b'
	
	
	
}

int		count_a_steps(t_stack *a, t_element* tmp_a, int median)
{
	t_element *last_a;
	int steps_a;
	
	steps_a = 0;
	last_a = get_last_elem(a);
	if (last_a->data == tmp_a->data)
	{
		rev_rotate_move(a);
		steps_a++;
	}
	else if (tmp_a->index >= median)
	{
		while(tmp_a->data != peek(a))
		{
			rotate_move(a);
			steps_a++;
		}
	}
	else if(tmp_a->index < median)
	{
		while(tmp_a->data != peek(a))
		{
			rev_rotate_move(a);
			steps_a++;
		}
	}
	return (steps_a);
}