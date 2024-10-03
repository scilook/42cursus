/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:43:06 by hyeson            #+#    #+#             */
/*   Updated: 2024/10/03 15:08:13 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*num;
	unsigned int	cnt;
	long long int	cp;

	if (n == 0)
		return (ft_strdup("0"));
	cp = n;
	cnt = 0;
	while (n != 0)
	{
		cnt++;
		n = n / 10;
	}
	num = (char *)malloc(sizeof(char) * (cnt + (int)(cp < 0)));
	if (num == NULL)
		return (NULL);
	if (cp < 0)
		cp = -cp;
	while (cp != 0)
	{
		num[cnt + (cp < 0)] = cp % 10 + '0';
		cp = cp / 10;
		cnt--;
	}
	return (num);
}
