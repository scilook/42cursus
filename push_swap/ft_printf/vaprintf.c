/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vaprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:50:14 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/25 08:02:13 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putstr_stdout(char *s, size_t *cnt)
{
	if (s == NULL)
		s = "(null)";
	ft_putstr_fd(s, 1);
	*cnt += ft_strlen(s);
}

static void	putchar_stdout(char c, size_t *cnt)
{
	ft_putchar_fd(c, 1);
	(*cnt)++;
}

static void	addr_encoder(void *addr, char *base, size_t *cnt)
{
	int		radix;
	int		i;
	char	chnbr[16];
	size_t	n;

	i = 0;
	radix = ft_strlen(base);
	if (addr == NULL)
	{
		putstr_stdout("(nil)", cnt);
		return ;
	}
	n = (size_t)addr;
	putstr_stdout("0x", cnt);
	while (n != 0)
	{
		chnbr[i++] = base[n % radix];
		n /= radix;
	}
	while (i != 0)
		putchar_stdout(chnbr[--i], cnt);
}

static void	base_encoder(long int n, char *base, size_t *cnt)
{
	int		radix;
	int		i;
	char	chnbr[16];

	i = 0;
	radix = ft_strlen(base);
	if (n == 0)
		putchar_stdout(base[0], cnt);
	if (n < 0)
	{
		n = -n;
		putchar_stdout('-', cnt);
	}
	while (n != 0)
	{
		chnbr[i++] = base[n % radix];
		n /= radix;
	}
	while (i != 0)
		putchar_stdout(chnbr[--i], cnt);
}

void	vaprintf(va_list ap, const char c, size_t *cnt)
{
	if (c == 's')
		putstr_stdout(va_arg(ap, char *), cnt);
	else if (c == 'c')
		putchar_stdout(va_arg(ap, int), cnt);
	else if (c == 'p')
		addr_encoder(va_arg(ap, void *), "0123456789abcdef", cnt);
	else if (c == 'd' || c == 'i')
		base_encoder(va_arg(ap, int), "0123456789", cnt);
	else if (c == 'u')
		base_encoder(va_arg(ap, unsigned int), "0123456789", cnt);
	else if (c == 'x')
		base_encoder(va_arg(ap, unsigned int), "0123456789abcdef", cnt);
	else if (c == 'X')
		base_encoder(va_arg(ap, unsigned int), "0123456789ABCDEF", cnt);
	else
		putchar_stdout('%', cnt);
}
