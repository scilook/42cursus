/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <me@geonhwan.kim>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:55:39 by geonhwki          #+#    #+#             */
/*   Updated: 2024/10/01 21:14:34 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*a;
	const unsigned char	*b;

	if (n == 0)
		return (0);
	a = (const unsigned char *)s1;
	b = (const unsigned char *)s2;
	while ((*a == *b) && --n)
	{
		++a;
		++b;
	}
	return (*a - *b);
}
