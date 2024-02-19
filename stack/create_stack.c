/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:43:06 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/19 19:21:03 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	parsing(int argc, char **argv, t_stack *stack)
{
	char	*str;
	char	**future_stack;

	str = ft_ex_join(argc, argv, " "); // deleted the name of programm from arguments
	if (!str)
		return (1);
	if (check_if_int(str) == 1)
		return (1);
	future_stack = ft_split(str, ' ');
	if (!future_stack)
		return (1);
	free(str);
	if (check_if_in_int(future_stack))
		return (1);
	return (create_stack(stack, future_stack));
}

int	create_stack(t_stack *stack, char	**future_stack)
{
	int		num_count;
	int		counter;
	int		num;

	counter = 0;
	num_count = arr_strlen(future_stack);
	while (future_stack[counter])
	{
		num = ft_atoi(future_stack[num_count - counter]);
		if (push(stack, num) == 1)
			return (1);
		counter++;
	}
	free_split(future_stack);
	if (check_dups(stack) == 1)
		return (1);
	return (0);
}
