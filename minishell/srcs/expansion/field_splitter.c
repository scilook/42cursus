/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_splitter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 01:47:53 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/17 00:32:30 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "libft.h"
#include "utils.h"

t_bool	should_split(char **words)
{
	int		i;
	t_list	*quotes;

	i = 0;
	while (words[i] != NULL)
	{
		quotes = find_quotes(words[i]);
		if (_count_words(words[i], " ", quotes) > 1)
		{
			ft_lstclear(&quotes, quote_destroy);
			return (TRUE);
		}
		ft_lstclear(&quotes, quote_destroy);
		++i;
	}
	return (FALSE);
}

void	field_split(char ***words_ptr, const char *ifs)
{
	t_list	*quotes;
	char	**new;
	char	**split_words;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = NULL;
	while ((*words_ptr)[i] != NULL)
	{
		quotes = find_quotes((*words_ptr)[i]);
		split_words = _split((*words_ptr)[i], ifs, quotes);
		j = 0;
		while (split_words[j] != NULL)
			word_add_to_last(&new, split_words[j++]);
		word_destroy_all(split_words);
		ft_lstclear(&quotes, quote_destroy);
		++i;
	}
	word_destroy_all((*words_ptr));
	(*words_ptr) = new;
}
