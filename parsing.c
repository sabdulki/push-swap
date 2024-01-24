/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:14:34 by sabdulki          #+#    #+#             */
/*   Updated: 2024/01/24 15:28:31 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arr_strlen(char **arr)
{
	int i = 0;
	while(arr[i])
		i++;
	return (i-1);
}

void	check_if_in_int(char **arr)
{
	int arg = 1;
	
	while(arr[arg])
	{
		if ((arr[arg][0] == '-' && ft_atoi(arr[arg]) >= 0) \
		|| (arr[arg][0] != '-' && ft_atoi(arr[arg]) < 0) )
			ft_error();
		arg++;
	}
}

void	check_if_int(char *str)
{
	int i = 0;
	while(str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			ft_error();
		i++;
	}
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
}

void parsing(int argc, char **argv, t_stack *stack)
{
	char *str;
	char **future_stack;
	int arg;
	int  num;
	
	str = ft_ex_join(argc, argv, " "); // deleted the name of programm from arguments
	// protection
	check_if_int(str);
	future_stack = ft_split(str, ' ');
	// protection
	check_if_in_int(future_stack);

	arg = arr_strlen(future_stack);
	printf("\narg: %d\n", arg);
	while(arg >= 0 && future_stack[arg])
	{
		num = ft_atoi(future_stack[arg]);
		stack->amount = push(stack, num); //, stack->amount);
		if (stack->amount == 0)
			ft_error();
		print_elements(stack);
		arg--;
	}
	check_dups(stack);
}