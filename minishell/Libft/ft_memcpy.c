/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:17:03 by geonhwki          #+#    #+#             */
/*   Updated: 2024/10/07 15:21:12 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest0, const void *src0, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*src;

	dest = dest0;
	src = src0;
	while (n--)
		*dest++ = *src++;
	return (dest0);
}
