/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:01:04 by hyeson            #+#    #+#             */
/*   Updated: 2024/10/06 12:08:30 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst;

	i = 0;
	dst = (unsigned char *)dest;
	if (dest - src < 0)
	{
		while (i < n)
		{
			dst[i] = *(unsigned char *)(src + i);
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			i++;
			dst[n - i] = *(unsigned char *)(src + n - i);
		}
	}
	return (dest);
}
