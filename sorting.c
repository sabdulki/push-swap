/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:09:57 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/09 19:15:15 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

int	sort(t_stack *a, t_stack *b)
{
	int			iter_count;
	int			i; 
	char 		flag;
	t_dict		*moving_num;

	iter_count = min(2, a->amount-3);
	flag = 'a';
	i = 1;
	// check(a);
	while(iter_count != 0)
	{
		push_move(a, b, flag);
		iter_count--;
	}
	// print_elements(b);
	while(a->amount != 3)
	{
		if (b->amount == 3)
			sort_three_rev(b);
		// printf("\n------%d new call from a to b ------\n", i);
		moving_num = find_most_profit_num(a, b, flag);
		make_a_move(a, b, moving_num, flag);
		// while(get_last_elem(b)->data != find_min(b)->data)
		// {
			if ((peek(b) == find_min(b)->data ) ||  (peek(b) < get_last_elem(b)->data))
			{
				printf("in_0_if\n");
				rotate_move(b, 'b');
			}
		// }
		// i++;
	}
	moving_num = NULL;
	sort_three(a, flag);
	flag = 'b';
	// i = 1;
	// теперь все делаю ровно наоборот.
	// нахожу target для числе в стэке b чтобы перекинуть их в a
	// считаю steps
	// сраниваю steps, выбираю наименьшее кол-во
	// передвигаю
	printf("\n\t\t\t\t\t\t----------PUSH BACK TO STACK A----------\n");
	while(b->amount != 0)
	{
		// printf("\n------%d new call from B to A ------\n", i);
		moving_num = find_most_profit_num(b, a, flag);
		make_a_move(b, a, moving_num, flag);
		// if (peek(a) == find_min(b)->data)
		// 	continue;
		if (peek(a) == find_max(a)->data)
			// (get_last_elem(a)->data != find_min(a)->data) ) //|| \(peek(a) > get_last_elem(a)->data &&
			//(get_last_elem(a)->data != find_max(a)->data))
			{
				printf("in 1 if statement\n");
				rotate_move(a, 'a');
		// i++;
				
			}
	}
	while(peek(a) != find_min(a)->data)
	{
		printf("in 2 if statement\n");
		if (get_last_elem(a)->data < peek(a))
		{
			// printf("in 2 if statement\n");
			rev_rotate_move(a, 'a');
		}
	}
	free(moving_num);
	return (0);
}

void	check(t_stack* a)
{
	t_stack *tmp;

	tmp = a;

	if (find_min(tmp)->data == get_last_elem(tmp)->data)
	{
		get_last_elem(tmp)->data = INT_MAX; 
	}
	if (is_ascending(tmp))
	{
		rev_rotate_move(a, 'a');
	}
	else
		printf("need smth else to sort\n");
	return ;
	
}