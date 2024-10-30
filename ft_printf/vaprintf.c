/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vaprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:50:14 by hyeson            #+#    #+#             */
/*   Updated: 2024/10/30 10:55:38 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	base_encoder(long long int n, char *base, size_t *cnt)
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

void	vaprintf(size_t *i, va_list ap, const char *s, size_t *cnt)
{
	int	va_int;

	if (s[*i] == 'c' && ++(*cnt))
		ft_putchar_fd(va_arg(ap, int), 1);
	if (s[*i] == 's')
		ft_putstr_fd(va_arg(ap, char *), 1, cnt);
	if (s[*i] == 'p')
	{
		ft_putstr_fd("0x", 1, cnt);
		base_encoder(va_arg(ap, int), "0123456789abcdef", cnt);
	}
	if (s[*i] == 'd' || s[*i] == 'i')
		base_encoder(va_arg(ap, int), "0123456789", cnt);
	if (s[*i] == 'u')
	{
		va_int = va_arg(ap, int);
		base_encoder(ABS(va_int), "0123456789", cnt);
	}
	if (s[*i] == 'x')
		base_encoder(va_arg(ap, int), "0123456789abcdef", cnt);
	if (s[*i] == 'X')
		base_encoder(va_arg(ap, int), "0123456789ABCDEF", cnt);
	if (s[(*i)++] == '%' && ++(*cnt))
		ft_putchar_fd('%', 1);
}
