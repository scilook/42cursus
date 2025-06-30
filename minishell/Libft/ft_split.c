/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:38:04 by geonhwki          #+#    #+#             */
/*   Updated: 2024/11/11 16:04:05 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

static int	wordlen(char *str, char c);
static char	*worddup(char *src, char c);
static int	count_words(char *str, char c);

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**result;
	bool	is_word_start;
	int		words_count;
	int		count;

	str = (char *)(s);
	words_count = count_words(str, c);
	result = malloc((words_count + 1) * sizeof(char *));
	is_word_start = true;
	count = 0;
	while (*str != '\0')
	{
		if (*str == c)
			is_word_start = true;
		else
		{
			if (is_word_start)
				result[count++] = worddup(str, c);
			is_word_start = false;
		}
		++str;
	}
	result[count] = NULL;
	return (result);
}

static char	*worddup(char *src, char c)
{
	char	*dest;
	char	*ptr;

	dest = malloc(wordlen(src, c) + 1);
	if (dest == NULL)
		return (NULL);
	ptr = dest;
	while (*src != '\0' && *src != c)
		*ptr++ = *src++;
	*ptr = '\0';
	return (dest);
}

static int	wordlen(char *str, char c)
{
	char	*s;

	s = str;
	while (*str != '\0' && *str != c)
		++str;
	return (str - s);
}

static int	count_words(char *str, char c)
{
	bool	is_word_start;
	int		count;

	is_word_start = true;
	count = 0;
	while (*str != '\0')
	{
		if (*str == c)
			is_word_start = true;
		else
		{
			if (is_word_start)
				count++;
			is_word_start = false;
		}
		++str;
	}
	return (count);
}
