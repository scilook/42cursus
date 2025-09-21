/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 20:39:02 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/16 23:02:25 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "minishell.h"
# include "utils.h"

void	expand_word(t_minishell *shell, char ***word_ptr);
void	expand_filename(t_minishell *shell, char **filename);
void	parameter_expand(t_minishell *shell, char **str_ptr);
void	ft_tilde_expand(t_minishell *shell, char **str_ptr);

t_bool	should_split(char **words);
void	field_split(char ***words_ptr, const char *ifs);
void	remove_quote(char **str_ptr);

#endif /* EXPANDER_H */
