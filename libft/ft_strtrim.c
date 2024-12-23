/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:41:52 by hyeson            #+#    #+#             */
/*   Updated: 2024/10/13 09:46:17 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	while (ft_strchr(set, s1[i]) != NULL && s1[i] != '\0')
		i++;
	j = 0;
	while ((ft_strlen(s1) - i) && ft_strchr(set, s1[ft_strlen(s1) - j - 1]))
		j++;
	str = ft_substr(s1, i, ft_strlen(s1) - i - j);
	return (str);
}
