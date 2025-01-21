/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:18:32 by hyeson            #+#    #+#             */
/*   Updated: 2024/10/11 19:02:00 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	littlelen;

	littlelen = ft_strlen(little);
	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i + littlelen <= len)
	{
		if (little[0] == big[i])
		{
			if (ft_strncmp(little, big + i, littlelen) == 0)
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
