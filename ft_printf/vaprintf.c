/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vaprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:50:14 by hyeson            #+#    #+#             */
/*   Updated: 2024/10/30 20:25:15 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	addr_encoder(size_t n, char *base, size_t *cnt)
{
	int		radix;
	int		i;
	char	chnbr[16];

	i = 0;
	radix = ft_strlen(base);
	if (n == 0)
		ft_putstr_fd("(nil)", 1, cnt);
	while (n != 0)
	{
		chnbr[i++] = base[n % radix];
		n /= radix;
	}
	while (i != 0 && ++(*cnt))
		ft_putchar_fd(chnbr[--i], 1);
}

static void	base_encoder(long int n, char *base, size_t *cnt)
{
	int		radix;
	int		i;
	char	chnbr[16];

	i = 0;
	radix = ft_strlen(base);
	if (n == 0 && ++(*cnt))
		ft_putchar_fd(base[0], 1);
	if (n < 0 && ++(*cnt))
	{
		n = -n;
		ft_putchar_fd('-', 1);
	}
	while (n != 0)
	{
		chnbr[i++] = base[n % radix];
		n /= radix;
	}
	while (i != 0 && ++(*cnt))
		ft_putchar_fd(chnbr[--i], 1);
}

void	vaprintf(size_t i, va_list ap, const char *s, size_t *cnt)
{
	long	va_long;
	char	*va_str;

	if (s[i] == 's')
		va_str = va_arg(ap, char *);
	if (s[i] == 's')
		ft_putstr_fd(va_str, 1, cnt);
	else
		va_long = va_arg(ap, long);
	if (s[i] == 'c' && ++(*cnt))
		ft_putchar_fd(va_long, 1);
	if (s[i] == 'p' && va_long != 0)
		ft_putstr_fd("0x", 1, cnt);
	if (s[i] == 'p')
		addr_encoder((size_t)va_long, "0123456789abcdef", cnt);
	if (s[i] == 'd' || s[i] == 'i')
		base_encoder((int)va_long, "0123456789", cnt);
	if (s[i] == 'u')
		base_encoder((va_long) << 1 >> 1, "0123456789", cnt);
	if (s[i] == 'x')
		base_encoder((size_t)va_long, "0123456789abcdef", cnt);
	if (s[i] == 'X')
		base_encoder((size_t)va_long, "0123456789ABCDEF", cnt);
	if (s[i] == '%' && ++(*cnt))
		ft_putchar_fd('%', 1);
}
