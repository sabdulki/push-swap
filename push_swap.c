/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:55:32 by sabdulki          #+#    #+#             */
/*   Updated: 2023/10/04 20:15:01 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*make_base_for_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->amount = 0;
	return (stack);
}

t_stack	*base_and_parsing(int argc, char **argv)
{
	t_stack	*stack;

	stack = make_base_for_stack();
	if (!stack)
		return (NULL);
	if (parsing(argc, argv, stack) == 1)
		return (destroy(stack), NULL);
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc <= 1)
		return (0);
	a = base_and_parsing(argc, argv);
	if (!a)
		ft_error();
	if (is_ascending(a))
		return (finish(a, NULL), 0);
	b = make_base_for_stack();
	if (!b)
	{
		finish (a, NULL);
		ft_error();
	}
	if (sort_all(a, b) == 1)
	{
		finish (a, NULL);
		ft_error();
	}
	return (0);
}

int	sort_all(t_stack *a, t_stack *b)
{
	sort_2_3(a);
	if (is_ascending(a))
		return (finish(a, b), 0);
	if (sort(a, b) == 1)
		return (1);
	if (is_ascending(a))
		return (finish(a, b), 0);
	return (0);
}
