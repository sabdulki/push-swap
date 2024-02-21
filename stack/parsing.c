/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:14:34 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/21 14:40:34 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	arr_strlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i - 1);
}

int	check_if_in_int(char **arr)
{
	int	arg;

	arg = 0;
	while (arr[arg])
	{
		if ((arr[arg][0] == '-' && ft_atoi(arr[arg]) >= 0) \
		|| (arr[arg][0] != '-' && ft_atoi(arr[arg]) < 0))
		{
			return (1);
		}
		arg++;
	}
	return (0);
}

int	check_if_int(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	check_dups(t_stack *stack)
{
	t_elem	*tmp;
	t_elem	*tmp2;

	tmp = stack->top;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->data == tmp2->data)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}
