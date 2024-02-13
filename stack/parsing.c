/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:14:34 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/13 14:17:38 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	arr_strlen(char **arr)
{
	int i;

	i = 0;
	while(arr[i])
		i++;
	return (i-1);
}

void	check_if_in_int(char **arr)
{
	int arg;

	arg = 1;
	while(arr[arg])
	{
		if ((arr[arg][0] == '-' && ft_atoi(arr[arg]) >= 0) \
		|| (arr[arg][0] != '-' && ft_atoi(arr[arg]) < 0) )
			ft_error();
		arg++;
	}
	return ;
}

void	check_if_int(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			ft_error();
		i++;
	}
	return ;
}

void check_dups(t_stack *stack)
{
	t_element *tmp;
	t_element *tmp2;

	tmp = stack->top;
	while(tmp)
	{
		tmp2 = tmp->next;
		while(tmp2)
		{
			if (tmp->data == tmp2->data)
				ft_error();
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return ;
}

void parsing(int argc, char **argv, t_stack *stack)
{
	char	*str;
	char	**future_stack;
	int		counter;
	int		num_count;
	int 	num;
	
	str = ft_ex_join(argc, argv, " "); // deleted the name of programm from arguments
	if (!str)
		ft_error();
	// protection
	check_if_int(str);
	future_stack = ft_split(str, ' ');
	if (!future_stack)
		ft_error();
	// protection
	free(str);
	check_if_in_int(future_stack);
	counter = 0;
	num_count = arr_strlen(future_stack);
	while(future_stack[counter])
	{
		num = ft_atoi(future_stack[num_count - counter]);
		if (push(stack, num))
			ft_error();
		counter++;
	}
	free_split(future_stack);
	check_dups(stack);
	return ;
}