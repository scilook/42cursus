/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:53:56 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/16 23:02:28 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "libft.h"
#include "utils.h"
#include <stdlib.h>

static int	word_get_words_count(char **words);

void	word_add_to_last(char ***words, char *word)
{
	int		count;
	char	**new_words;

	if (words == NULL || word == NULL)
		return ;
	count = word_get_words_count(*words);
	new_words = ft_malloc(sizeof(char *) * (count + 2));
	ft_memcpy(new_words, *words, sizeof(char *) * count);
	new_words[count] = ft_strdup(word);
	new_words[count + 1] = NULL;
	if (*words)
		free(*words);
	*words = new_words;
}

void	word_destroy_all(char **words)
{
	int	i;

	if (words == NULL)
		return ;
	i = 0;
	while (words[i] != NULL)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

static int	word_get_words_count(char **words)
{
	int	count;

	count = 0;
	if (words == NULL)
		return (0);
	while (words[count] != NULL)
		count++;
	return (count);
}
