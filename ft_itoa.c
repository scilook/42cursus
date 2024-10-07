/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:43:06 by hyeson            #+#    #+#             */
/*   Updated: 2024/10/06 17:38:47 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_decimal_count(int n)
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

char	*ft_itoa(int n)
{
	char			*num;
	int				flag;
	unsigned int	cnt;
	long long int	cp;

	if (n == 0)
		return (ft_strdup("0"));
	cp = n;
	flag = 0;
	cnt = ft_decimal_count(n);
	num = (char *)malloc(sizeof(char) * (cnt + (cp < 0)));
	if (num == NULL)
		return (NULL);
	if (cp < 0)
	{
		num[0] = '-';
		cp = -cp;
		flag = 1;
	}
	while (cp != 0)
	{
		num[--cnt + flag] = cp % 10 + '0';
		cp = cp / 10;
	}
	return (num);
}
