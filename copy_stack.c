/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:41:08 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/01 20:07:49 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_stack*	copy_stack(t_stack *stack)
// {
// 	t_stack *a;
// 	t_element *tmp_s;
// 	t_element *tmp_a;
// 	int amount;

// 	amount = 0;
// 	a = make_base_for_stack();
// 	tmp_s = stack->top;
// 	tmp_a = a->top;
// 	while(tmp_s)
// 	{
// 		tmp_a->data = tmp_s->data;
// 		tmp_s = tmp_s->next;
// 		tmp_a = tmp_a->next;
// 		a->amount = amount++;
// 	}
// 	print_elements(a);
// 	return (a);
// }