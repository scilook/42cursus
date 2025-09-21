/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:21:36 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/16 23:02:22 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest0, const void *src0, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*src = src0;

	dest = dest0;
	if (src < dest)
		while (n--)
			dest[n] = src[n];
	else if (dest != src && n != 0)
		ft_memcpy(dest, src, n);
	return (dest0);
}
