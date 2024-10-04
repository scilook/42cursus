/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:42:31 by hyeson            #+#    #+#             */
/*   Updated: 2024/10/03 20:39:37 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* size_t	ft_chrcnt(const char *s, const char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			cnt++;
		i++;
	}
	return (cnt);
} */

size_t	word_count(const char *s, const char c)
{
	size_t	i;
	size_t	cnt;
	size_t	i_am_c;

	cnt = 0;
	i_am_c = 1;
	i = 0;
	while (s[i] != '\0')
	{
	if (i_am_c == 1 && s[i] != c)
	{
		i_am_c = 0;
		cnt++;
	}
	if (i_am_c == 0 && s[i] == c)
	{
		i_am_c = c;
	}
	i++;
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
	size_t	i;

	ptr = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < word_count(s, c))
	{
		while (s[i] == c)
			i++;
		ptr[i] = (char *)malloc(sizeof(char) * (ft_strchr(s, c) - s + 1));
		if (ptr[i] == NULL)
		{
			while (i != 0)
				free(ptr[--i]);
			return (NULL);
		}
		ptr[i] = ft_strcdup(s, c);
		while (s[i] != c)
			i++;
	}
	ptr[i] = 0;
	return (ptr);
}

		// j = 0;
		// while (*(str + i) != c)
		// 	ptr[i][j++] = *((char *)str + i);
		// ptr[i][j] = '\0';