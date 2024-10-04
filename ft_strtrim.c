/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:41:52 by hyeson            #+#    #+#             */
/*   Updated: 2024/10/03 19:55:31 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*str;

	str = (char *)s1;
	i = 0;
	while (ft_strchr(set, str[i]) != NULL)
	{
		ft_strlcpy(str, str + 1, ft_strlen(str));
		i++;
	}
	i = 0;
	while (ft_strrchr(set, str[i]) != NULL)
	{
		ft_strlcpy(str, str, ft_strlen(str));
		i++;
	}
	return (str);
}
