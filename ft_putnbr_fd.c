/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:58:33 by hyeson            #+#    #+#             */
/*   Updated: 2024/10/12 15:54:38 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	decimal_count(int n)
{
	unsigned int	cnt;

	cnt = 0;
	while (n != 0)
	{
		cnt++;
		n = n / 10;
	}
	return (cnt);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long int	cp;
	size_t			digit;
	char			nbr[11];

	digit = decimal_count(n);
	if (n == 0)
		ft_putchar_fd('0', fd);
	cp = n;
	if (cp < 0)
	{
		ft_putchar_fd('-', fd);
		cp = -cp;
	}
	nbr[digit] = '\0';
	while (cp != 0)
	{
		nbr[--digit] = cp % 10 + '0';
		cp /= 10;
	}
	ft_putstr_fd(nbr, fd);
}
