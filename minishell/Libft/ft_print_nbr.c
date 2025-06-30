/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:07:18 by geonhwki          #+#    #+#             */
/*   Updated: 2024/10/16 22:36:35 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(size_t nb, int *out_length)
{
	if (nb == 0)
	{
		write(1, "(nil)", 5);
		*out_length = 5;
		return ;
	}
	*out_length = write(1, "0x", 2);
	ft_putulnbr_base(nb, "0123456789abcdef", out_length);
}

void	ft_putnbr(int nb, int *out_length)
{
	if (nb == -2147483648)
	{
		*out_length = 11;
		ft_putstr_fd("-2147483648", 1);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		++(*out_length);
		ft_putchar_fd('-', 1);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, out_length);
		ft_putnbr(nb % 10, out_length);
		return ;
	}
	ft_putchar_fd(nb + '0', 1);
	++(*out_length);
}

void	ft_putunbr_base(unsigned int nb, const char *base, int *out_length)
{
	const unsigned int	n = ft_strlen(base);

	if (nb >= n)
	{
		ft_putunbr_base(nb / n, base, out_length);
		ft_putunbr_base(nb % n, base, out_length);
	}
	else
	{
		ft_putchar_fd(base[nb], 1);
		++(*out_length);
	}
}

void	ft_putulnbr_base(size_t nb, const char *base, int *out_length)
{
	const size_t	n = ft_strlen(base);

	if (nb >= n)
	{
		ft_putulnbr_base(nb / n, base, out_length);
		ft_putulnbr_base(nb % n, base, out_length);
	}
	else
	{
		ft_putchar_fd(base[nb], 1);
		++(*out_length);
	}
}
