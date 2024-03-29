/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:39:44 by sabdulki          #+#    #+#             */
/*   Updated: 2023/09/30 18:42:06 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

// change the plases of create_memory in join, another part in another function
// add '\0' everywhere were ands the string

int	ft_ex_strlen(char *str, char flag)
{
	int	len;
	int	space;

	len = 0;
	space = 0;
	while (str[len] != '\0')
	{
		if (str[len] == ' ')
			space++;
		len++;
	}
	if (flag == 'a')
	{
		if (len == space)
			return (-1);
	}
	return (len);
}

int	add_separator(char *sep, char *str, int big_str_ctn)
{
	int	sep_chars;

	sep_chars = 0;
	while (sep[sep_chars] != '\0')
	{
		str[big_str_ctn] = sep[sep_chars];
		sep_chars++;
		big_str_ctn++;
	}
	return (sep_chars);
}

char	*make_an_array(int size, char **strs, char *sep, char *str)
{
	int		index;
	int		big_str_ctn;
	int		chars_in_small;

	index = 1;
	big_str_ctn = 0;
	chars_in_small = 0;
	while (index < size)
	{
		str[big_str_ctn] = strs[index][chars_in_small];
		if (strs[index][chars_in_small] == '\0')
		{
			if (index != size - 1)
				big_str_ctn += add_separator(sep, str, big_str_ctn);
			chars_in_small = 0;
			index++;
		}
		else
		{
			chars_in_small++;
			big_str_ctn++;
		}
	}
	str[big_str_ctn] = '\0';
	return (str);
}

char	*ft_ex_join(int size, char **strs, char *sep)
{
	char	*str;
	int		len_all;
	int		index;
	int		len_sep;

	len_all = 0;
	index = 1;
	len_sep = 0;
	if (size == 0)
		return (NULL);
	while (index < size)
	{
		if (ft_ex_strlen(strs[index], 'a') > 0)
			len_all += ft_ex_strlen(strs[index], 'a');
		else
			return (NULL);
		index++;
	}
	len_sep = ft_ex_strlen(sep, 's') * (size - 1 -1);
	str = malloc(sizeof(char) * (len_all + len_sep + 1));
	make_an_array(size, strs, sep, str);
	return (str);
}
