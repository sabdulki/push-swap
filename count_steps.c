/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:35:43 by sabdulki          #+#    #+#             */
/*   Updated: 2024/01/31 14:44:16 by sabdulki         ###   ########.fr       */
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
int count_steps(t_stack *a, t_stack *b, t_element *tmp_a,  t_element *target)
{
	int steps_a;
	int steps_b;
	int all_steps;

	steps_a = 0;
	steps_b = 0;

	steps_a = count_a_steps(a, tmp_a);
	steps_b = count_b_steps(b, target);
	
	all_steps = steps_a + steps_b + 1;   // +1 for push_move
	return (all_steps);
}

int		count_a_steps(t_stack *a, t_element* tmp_a)
{
	// t_element *last_a;
	int steps_a;
	int median;
	
	steps_a = 0;
	median = a->amount / 2;
	// last_a = get_last_elem(a);
	// if (last_a->data == tmp_a->data)
	// {
	// 	//rev_rotate_move(a);
	// 	steps_a += 1;
	// }
	if (tmp_a->index <= median)
	{
		steps_a = tmp_a->index - 1;
		// while(tmp_a->data != peek(a))
		// {
		// 	rotate_move(a);
		// 	steps_a++;
		// }
	}
	else if(tmp_a->index > median)
	{

		steps_a = a->amount - tmp_a->index + 1;
		// while(tmp_a->data != peek(a))
		// {
		// 	rev_rotate_move(a);
		// 	steps_a++;
		// }
	}
	return (steps_a);
}

int		count_b_steps(t_stack *b, t_element *target)
{
	t_element *tmp_b;
	// t_element *last_b;
	int steps_b;
	int median;

	tmp_b = find_target_index(b, target);
	// last_b = get_last_elem(b);
	median = b->amount / 2;
	steps_b = 0;

	// if (last_b->data == tmp_b->data)
	// {
	// 	//rev_rotate_move(a);
	// 	steps_b += 1;
	// }
	if (tmp_b->index <= median)
	{
		steps_b = tmp_b->index - 1;
		// while(tmp_a->data != peek(a))
		// {
		// 	rotate_move(a);
		// 	steps_a++;
		// }
	}
	else if (tmp_b->index > median)
	{

		steps_b = b->amount - tmp_b->index + 1;
		// while(tmp_a->data != peek(a))
		// {
		// 	rev_rotate_move(a);
		// 	steps_a++;
		// }
	}
	return (steps_b);
	
}

t_element *find_target_index(t_stack *b, t_element *target)
{
	t_element *tmp;
	
	tmp = b->top;
	while(tmp)
	{
		if (tmp->data == target->data)
			return (tmp);
		tmp = tmp->next;
	}
	printf("haven't found element with the same number. Return head of stack");
	return(b->top);
}
