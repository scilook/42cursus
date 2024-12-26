/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:42:31 by hyeson            #+#    #+#             */
/*   Updated: 2024/12/26 17:42:28 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char *s, const char c)
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

static int	strclen(char *s, char c)
{
	int	cnt;

	cnt = 0;
	while (s[cnt] != c)
	{
		cnt++;
	}
	return (cnt);
}

static char	*ft_strcdup(char *s, const char c)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (s[i] == '\'')
	{
		s++;
		while (s[i] != '\'')
		{
			if (s[i] == ' ')
				s[i] = -1;
			i++;
		}
	}
	ptr = (char *)malloc(sizeof(char) * (strclen(s, c) + 1));
	if (ptr == NULL)
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

static int	free_ptr(char **ptr, int i)
{
	while (i >= 0)
	{
		free(ptr[i]);
		i--;
	}
	free(ptr);
	return (1);
}

char	**ft_split(char *s, char c)
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
	ptr[j] = NULL;
	return (ptr);
}
