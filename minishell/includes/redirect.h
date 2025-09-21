/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 21:28:27 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/16 23:02:26 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# include "command.h"
# include "minishell.h"

/* REDIRECT */
t_redirect	*redirect_init(t_redirect *next, char *here_doc_eof);
void		redirect_destroy_all(t_redirect *redirect);
void		redirect_add_to_last(t_minishell *shell, t_redirect **head,
				t_redirect *new);

#endif /* REDIRECT_H */
