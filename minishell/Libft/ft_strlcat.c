/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:06:22 by geonhwki          #+#    #+#             */
/*   Updated: 2024/10/05 19:07:36 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	src_len;
	size_t	dest_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	count = 0;
	if (dest_len >= size)
		return (src_len + size);
	while (*dest != '\0')
		++dest;
	while (*src != '\0' && count < size - dest_len - 1)
	{
		*dest++ = *src++;
		count++;
	}
	*dest = '\0';
	return (src_len + dest_len);
}
