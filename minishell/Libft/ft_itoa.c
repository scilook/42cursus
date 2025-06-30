/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:55:06 by geonhwki          #+#    #+#             */
/*   Updated: 2024/10/09 09:32:42 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	calc_length(int nb);
static void		itoa_recursive(int n, char *buf);
static void		putchar_buf(char c, char *buf);

char	*ft_itoa(int n)
{
	size_t	length;
	char	*result;

	length = calc_length(n);
	result = malloc(length + 1);
	*result = '\0';
	itoa_recursive(n, result);
	return (result);
}

static void	itoa_recursive(int nb, char *buf)
{
	if (nb == -2147483648)
	{
		ft_memcpy(buf, "-2147483648", 12);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		putchar_buf('-', buf);
	}
	if (nb >= 10)
	{
		itoa_recursive(nb / 10, buf);
		itoa_recursive(nb % 10, buf);
	}
	else
		putchar_buf(nb + '0', buf);
}

static size_t	calc_length(int nb)
{
	size_t	length;

	length = 0;
	if (nb == -2147483648)
		return (11);
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		length = 1;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb /= 10;
		++length;
	}
	return (length);
}

static void	putchar_buf(char c, char *buf)
{
	while (*buf != '\0')
		++buf;
	*buf++ = c;
	*buf = '\0';
}
