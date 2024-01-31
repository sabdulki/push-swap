/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:51:56 by sabdulki          #+#    #+#             */
/*   Updated: 2024/01/31 20:29:43 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "target.h"

t_dict *	find_most_profit_num (t_stack *a, t_stack *b) 
{
	t_element *tmp_a;
	// t_element *tmp_b;
	t_dict *step_dict;
	t_dict *step_h_dict;
	t_dict *head_dict;
	t_dict *dict;
	t_element *target;
	int steps;
	t_dict*	moving_num;
	
	target = malloc(sizeof(t_element));
	tmp_a = a->top;
	// tmp_b = b->top;

	head_dict = create_dictinary(b);
	step_h_dict = create_dictinary(a);
	step_dict = step_h_dict;
	while(tmp_a)
	{
		dict = find_value(tmp_a->data, b, head_dict);
		target->data = find_target(dict, a, b);
		step_dict->a_int = tmp_a->data;
		step_dict->b_int = target->data;
		printf("\ntarget for '%d' number of 'a' stack is: %d\n", tmp_a->data, target->data);
		// я нашла число, к которому пойдет первое число из стака а.
		// теперь мне надо посчитать количество шагов для первого числа из стака а до его таргета.
		steps = count_steps(a, b, tmp_a, target);
		step_dict->value = steps;
		// printf("have to accomplish  %d  steps to move num\n", steps);
		tmp_a = tmp_a->next;
		step_dict = step_dict->next;
	}
	// print_list(step_h_dict);
	//теперь беру step_h_dict и ищу в нем самый маленький value. Возвращаю чилсо int_a и 
	// отдельной функцией совершаю перемещение (move).
	moving_num = step_find_min(step_h_dict);
	//free (step-h_dict);
	printf("the moving num is: %d\n", moving_num->a_int);
	return (moving_num);
}

int		find_target(t_dict* head_dict, t_stack *a, t_stack *b) // находит target-числло из b  для ОДНОГО числа из стака а
{
	t_dict *dict_node;
	int target;
	int pos;
	int neg;
	int i;
	
	dict_node = head_dict;
	target = 0;
	pos = 0;
	neg = 0;
	i = 0;
	target = target_for_max_min(dict_node, a, b);
	if (target != 0) // NOT SAFE!!!!
	{
		// free_dict(head_dict);
		return (target);
	}
	while(dict_node)
	{
		if (dict_node->value >= 0)
			pos++;
		else if (dict_node->value < 0)
			neg++;
		i++;
		dict_node = dict_node->next;
	}
	if (i == pos) //all values of dict are posistive
		target = l_find_min(head_dict);
	else if (i == neg) // || (i != neg && i != pos)) // all values of dict are negative
		target = l_find_max(head_dict); // values are both positive and negative
	else if (i != neg && i != pos)
	{
		// find the min value in pos values
		printf("\nl_find_pos!!\n");
		target = l_find_min_pos(head_dict);
	}
	// free_dict(head_dict);
	return (target);
}

int	target_for_max_min(t_dict *head_dict, t_stack *a, t_stack *b)
{
	t_element* min_in_a;
	t_element* max_in_a;
	// t_element* min_in_b;
	t_element* max_in_b;

	min_in_a = find_min(a);
	max_in_a = find_max(a);
	// min_in_b = find_min(b);
	max_in_b = find_max(b);
	if (head_dict->a_int == min_in_a->data)
		return (max_in_b->data);
	else if (head_dict->a_int == max_in_a->data)
		return (max_in_b->data);
	return (0);
}

t_dict*	find_value(int num_a, t_stack *b, t_dict *head_dict) // находит все value для ОДНОГО числа из стака а
{
	t_element *tmp_b;
	t_dict *dict_node;

	tmp_b = b->top;
	dict_node = head_dict;
	// работать только с одниим числом из стака а
	while(tmp_b)
	{
		dict_node->a_int = num_a; // у list-a!!!!
		dict_node->value = num_a - tmp_b->data;
		dict_node->b_int = tmp_b->data;
		dict_node = dict_node->next;
		tmp_b = tmp_b->next;
	}
	// print_list(head_dict);
	return (head_dict); // или все же dict_node??
}

int		l_find_min_pos(t_dict *dict)
{
	int min_positive_value;
	t_dict *tmp;

	tmp = dict;
	min_positive_value = -1; // Инициализируем минимальное положительное значение отрицательным числом
    while (tmp != NULL) 
	{
        if (tmp->value > 0 && (min_positive_value == -1 || tmp->value < min_positive_value)) 
		{
            min_positive_value = tmp->value;
        }
        tmp = tmp->next;
    }

    return (min_positive_value);

	
	// t_dict *tmp;
	// t_dict *min;

	// tmp = dict;
	// // min = dict->next;
	// min = dict;
	// while(tmp)
	// {
	// 	if (tmp->value < 0) //|| min->value < 0)
	// 	{
	// 		tmp = tmp->next;
	// 		continue ;
	// 	}
	// 	else if (tmp->value < min->value) //  && tmp->value >= 0 && min->value >= 0)
	// 	{	
	// 		min = tmp;
			
	// 	}
	// 	tmp = tmp->next;
	// }
	// // printf("\nthe min is: %d\n", min->b_int);

	// return (min->b_int);
}
