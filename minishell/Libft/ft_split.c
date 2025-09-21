/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:38:04 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/16 23:02:23 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

static int	wordlen(char *str, const char *charset);
static char	*worddup(char *src, const char *charset);
static int	count_words(char *str, const char *charset);

char	**ft_split(char const *s, const char *charset)
{
	char	*str;
	char	**result;
	bool	is_word_start;
	int		words_count;
	int		count;

	str = (char *)(s);
	words_count = count_words(str, charset);
	result = malloc((words_count + 1) * sizeof(char *));
	is_word_start = true;
	count = 0;
	while (*str != '\0')
	{
		if (ft_strchr(charset, *str) != NULL)
			is_word_start = true;
		else
		{
			if (is_word_start)
				result[count++] = worddup(str, charset);
			is_word_start = false;
		}
		++str;
	}
	result[count] = NULL;
	return (result);
}

static char	*worddup(char *src, const char *charset)
{
	char	*dest;
	char	*ptr;

	dest = malloc(wordlen(src, charset) + 1);
	if (dest == NULL)
		return (NULL);
	ptr = dest;
	while (*src != '\0' && ft_strchr(charset, *src) == NULL)
		*ptr++ = *src++;
	*ptr = '\0';
	return (dest);
}

static int	wordlen(char *str, const char *charset)
{
	char	*s;

	s = str;
	while (*str != '\0' && ft_strchr(charset, *str) == NULL)
		++str;
	return (str - s);
}

static int	count_words(char *str, const char *charset)
{
	bool	is_word_start;
	int		count;

	is_word_start = true;
	count = 0;
	while (*str != '\0')
	{
		if (ft_strchr(charset, *str) != NULL)
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
