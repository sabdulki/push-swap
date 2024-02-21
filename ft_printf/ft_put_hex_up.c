/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:00:35 by sabdulki          #+#    #+#             */
/*   Updated: 2024/02/21 18:16:29 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex_up(unsigned int num)
{
	char	*str;
	int		res;

	str = "0123456789ABCDEF";
	res = 0;
	if (num / 16 != 0)
		res += ft_put_hex_up(num / 16);
	return (res + ft_putchar(str[num % 16]));
}
