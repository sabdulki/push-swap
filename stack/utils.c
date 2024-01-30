/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:18:49 by sabdulki          #+#    #+#             */
/*   Updated: 2023/10/04 17:26:36 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void ft_error(void)
{
	write(1, "Error\n", 6);
	// free everything!!!!!!
	exit(0);
}

void print_args(char **argv)
{
	int arg = 1;
	printf("The arguments are:\n");
	while(argv[arg])
		printf("%s\n", argv[arg++]);
	printf("---------\n");
}

void print_elements(t_stack* stack)
{
	if (is_empty(stack))
	{
		printf("there are no elements in the stack 'cause it is empty!\n");
		return ;
	}
	printf("the elements of stack are:\n");
	t_element *head;
	
	head = stack->top;
	while(head)
	{
		printf("%d\n", head->data);
		head = head->next;
	}
}

void print_elem_index(t_stack* stack)
{
	if (is_empty(stack))
	{
		printf("there are no elements in the stack 'cause it is empty!\n");
		return ;
	}
	printf("the elements of stack are:\n");
	t_element *head;
	
	head = stack->top;
	while(head)
	{
		printf("num: %d - index: %d\n", head->data, head->index);
		head = head->next;
	}
}


void	change_index(t_stack* stack)
{
	t_element	*tmp_top;
	int			index;

	tmp_top = stack->top;
	index = 1;
	while(tmp_top)
	{
		tmp_top->index = index++;
		tmp_top = tmp_top->next;
	}
	// print_elem_index(stack);
}

/*
1  -> x
2	1	
3	2
4	3
5	4

*/