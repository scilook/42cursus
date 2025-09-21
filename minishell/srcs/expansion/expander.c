/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 01:05:58 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/17 17:38:20 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "minishell.h"

void	expand_word(t_minishell *shell, char ***words_ptr)
{
	char	**words;
	int		i;

	i = 0;
	words = *words_ptr;
	while (words[i] != NULL)
	{
		ft_tilde_expand(shell, &words[i]);
		parameter_expand(shell, &words[i]);
		++i;
	}
	field_split(words_ptr, " ");
	words = *words_ptr;
	i = 0;
	while (words[i] != NULL)
		remove_quote(&words[i++]);
}

void	expand_filename(t_minishell *shell, char **filename)
{
	if (*filename == NULL)
		return ;
	ft_tilde_expand(shell, filename);
	parameter_expand(shell, filename);
}
