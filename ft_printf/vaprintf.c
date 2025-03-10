/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vaprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:50:14 by hyeson            #+#    #+#             */
/*   Updated: 2025/01/25 15:22:48 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (*(s + cnt))
	{
		cnt++;
	}
	return (cnt);
}

static void	ft_putstr_fd(char *s, int fd, size_t *cnt)
{
	if (s == NULL)
		s = "(null)";
	write(fd, s, ft_strlen(s));
	*cnt += ft_strlen(s);
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
		return (ft_putstr_fd("(nil)", 1, cnt));
	n = (size_t)addr;
	ft_putstr_fd("0x", 1, cnt);
	while (n != 0)
	{
		chnbr[i++] = base[n % radix];
		n /= radix;
	}
	while (i != 0)
		ft_putchar_fd(chnbr[--i], 1, cnt);
}

static void	base_encoder(long int n, char *base, size_t *cnt)
{
	int		radix;
	int		i;
	char	chnbr[16];

	i = 0;
	radix = ft_strlen(base);
	if (n == 0)
		ft_putchar_fd(base[0], 1, cnt);
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', 1, cnt);
	}
	while (n != 0)
	{
		chnbr[i++] = base[n % radix];
		n /= radix;
	}
	while (i != 0)
		ft_putchar_fd(chnbr[--i], 1, cnt);
}

void	vaprintf(va_list ap, const char c, size_t *cnt)
{
	if (c == 's')
		ft_putstr_fd(va_arg(ap, char *), 1, cnt);
	else if (c == 'c')
		ft_putchar_fd(va_arg(ap, int), 1, cnt);
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
		ft_putchar_fd('%', 1, cnt);
}
