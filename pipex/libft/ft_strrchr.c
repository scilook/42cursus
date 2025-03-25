/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:45:52 by hyeson            #+#    #+#             */
/*   Updated: 2024/10/13 09:38:56 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		flag;
	char	*tmp;

	i = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			tmp = ((char *)s + i);
			flag = 1;
		}
		i++;
	}
	if (c == '\0')
	{
		tmp = ((char *)s + i);
		flag = 1;
	}
	if (flag == 1)
	{
		return (tmp);
	}
	return (NULL);
}
