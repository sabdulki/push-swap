/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:25:12 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/21 16:39:13 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_mini_len(const char *str, char sep)
{
	int	len;

	len = 0;
	while (str[len] != '\0' && str[len] != sep)
		len++;
	return (len);
}

int	count_words(const char *str, char sep)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		if (str[i] == sep && str[i + 1] == '\0')
			break ;
		else if (str[i] == sep && str[i + 1] != sep)
			words++;
		i++;
	}
	if (str[0] != sep)
		words++;
	return (words);
}

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free (arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(const char *arr, char sep)
{
	char	**main;
	int		word_counter;
	int		i;
	int		words;

	if (!arr)
		return (0);
	word_counter = 0;
	i = 0;
	words = count_words(arr, sep);
	main = malloc(sizeof(char *) * (words + 1));
	if (!main)
		return (0);
	while (arr[i] && word_counter < words)
	{
		while (arr[i] == sep)
			i++;
		main[word_counter] = ft_substr(arr, i, ft_mini_len(&arr[i], sep));
		if (!main[word_counter++])
			return (free_split(main), NULL);
		i += ft_mini_len(&arr[i], sep);
	}
	main[word_counter] = 0;
	return (main);
}

// int main(void)
// {
//     char const *arr = "  a cat is  eating fish  ";
//     char sep = ' ';
//     char **result = ft_split(arr, sep);
//     while (*result)  //in start one and first string
//         printf("%s\n", *result++);
// }

/*
for count words:
	while (str[i] == sep)
		i++;
	if (str[i])
		words++;
	i += ft_len_of_mini_str(str+i, sep);
*/