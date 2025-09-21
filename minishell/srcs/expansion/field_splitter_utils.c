/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_splitter_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 00:31:38 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/17 00:32:37 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "libft.h"
#include "utils.h"

char	**_split(char const *s, const char *charset, t_list *quotes)
{
	char	*str;
	char	**result;
	t_bool	is_word_start;
	int		count;

	str = (char *)(s);
	result = malloc((_count_words(str, charset, quotes) + 1) * sizeof(char *));
	is_word_start = TRUE;
	count = 0;
	while (*str != '\0')
	{
		if (ft_strchr(charset, *str) != NULL && !is_in_quote(quotes, str))
			is_word_start = TRUE;
		else
		{
			if (is_word_start)
				result[count++] = worddup(str, charset, quotes);
			is_word_start = FALSE;
		}
		++str;
	}
	if (count == 0)
		result[count++] = worddup(str, charset, quotes);
	result[count] = NULL;
	return (result);
}

char	*worddup(char *src, const char *charset, t_list *quotes)
{
	char	*dest;
	char	*ptr;

	dest = malloc(_wordlen(src, charset, quotes) + 1);
	if (dest == NULL)
		return (NULL);
	ptr = dest;
	while (*src != '\0' && (ft_strchr(charset, *src) == NULL
			|| is_in_quote(quotes, src)))
		*ptr++ = *src++;
	*ptr = '\0';
	return (dest);
}

int	_wordlen(char *str, const char *charset, t_list *quotes)
{
	char	*s;

	s = str;
	while (*str != '\0' && (ft_strchr(charset, *str) == NULL
			|| is_in_quote(quotes, str)))
		++str;
	return (str - s);
}

int	_count_words(char *str, const char *charset, t_list *quotes)
{
	t_bool	is_word_start;
	int		count;

	is_word_start = TRUE;
	count = 0;
	while (*str != '\0')
	{
		if (ft_strchr(charset, *str) != NULL && !is_in_quote(quotes, str))
			is_word_start = TRUE;
		else
		{
			if (is_word_start)
				count++;
			is_word_start = FALSE;
		}
		++str;
	}
	if (count == 0)
		count = 1;
	return (count);
}
