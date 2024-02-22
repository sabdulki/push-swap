/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:56:57 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/22 19:52:07 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		ft_isdigit(int d);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *c);
int		ft_atoi(const char *arr);
char	*ft_substr(char const *arr, unsigned int start, size_t len);
char	**ft_split(const char *arr, char sep);
void	free_split(char **arr);
#endif