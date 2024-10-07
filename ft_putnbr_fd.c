/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:58:33 by hyeson            #+#    #+#             */
/*   Updated: 2024/10/06 17:37:54 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

static unsigned int	decimal_count(int n)
{
	unsigned int	power;

	power = 0;
	while (n != 0)
	{
		power++;
		n = n / 10;
	}
	return (power);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long int	cp;
	size_t			power;
	char			digit;

	power = decimal_count(n);
	if (n == 0)
		ft_putchar_fd('0', fd);
	cp = n;
	if (cp < 0)
	{
		ft_putchar_fd('-', fd);
		cp = -cp;
	}
	while (cp != 0 && power--)
	{
		digit = cp / ft_recursive_power(10, power);
		ft_putchar_fd(digit + '0', fd);
		cp = cp - digit * ft_recursive_power(10, power);
	}
}
