/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:42:31 by hyeson            #+#    #+#             */
/*   Updated: 2024/10/04 22:24:17 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
			i_am_c = 1;
		}
		i++;
	}
	return (cnt);
}

char	*ft_strcdup(const char *s, const char c)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (*(s + i) != c)
	{
		ptr[i] = *((char *)s + i);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	free_ptr(char **ptr, int i)
{
	while (i >= 0)
	{
		free(ptr[i]);
		i--;
	}
	free(ptr);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	i;
	size_t	j;

	ptr = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (j < word_count(s, c))
	{
		while (s[i] == c)
			i++;
		if (ft_strchr(s + i, c) == NULL)
			ptr[j] = ft_strcdup(s + i, '\0');
		else
			ptr[j] = ft_strcdup(s + i, c);
		if (ptr[j] == NULL && free_ptr(ptr, j - 1))
			return (NULL);
		while (s[i] != c)
			i++;
		j++;
	}
	ptr[j] = 0;
	return (ptr);
}
