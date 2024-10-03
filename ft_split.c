/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:42:31 by hyeson            #+#    #+#             */
/*   Updated: 2024/10/03 11:18:17 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_chrcnt(const char *s, const char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			cnt++;
	}
	return (cnt);
}

char	*ft_strcdup(const char *s, const char c)
{
	size_t	i;
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * ft_strlen(s));
	i = 0;
	while (*(s + i) != c)
	{
		ptr[i] = *((char *)s + i);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	char	*str;
	size_t	i;

	str = ft_strdup(s);
	ptr = (char **)malloc(sizeof(char *) * (ft_chrcnt(s, c) + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < ft_chrcnt(s, c))
	{
		ptr[i] = (char *)malloc(sizeof(char) * (ft_strchr(str, c) - str + 1));
		if (ptr[i] == NULL)
		{
			while (i != 0)
				free(ptr[--i]);
			return (NULL);
		}
		ptr[i] = ft_strcdup(str, c);
		str = ft_strchr(str, c);
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

		// j = 0;
		// while (*(str + i) != c)
		// 	ptr[i][j++] = *((char *)str + i);
		// ptr[i][j] = '\0';