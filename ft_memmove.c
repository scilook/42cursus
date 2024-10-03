/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:01:04 by hyeson            #+#    #+#             */
/*   Updated: 2024/10/03 13:58:16 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)dest;
	if (dest - src < 0)
	{
		while (i < n)
		{
			ptr[i] = *(char *)(src + i);
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			i++;
			ptr[n - i] = *(char *)(src + n - i);
		}
	}
	return (dest);
}
