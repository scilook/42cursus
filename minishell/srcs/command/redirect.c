/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 21:52:14 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/16 23:02:27 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "expander.h"
#include "minishell.h"
#include "redirect.h"
#include "utils.h"
#include <stdlib.h>

t_redirect	*redirect_init(t_redirect *next, char *here_doc_eof)
{
	t_redirect	*new;

	new = ft_malloc(sizeof(t_redirect));
	new->redirectee.dest = -1;
	new->redirectee.filename = NULL;
	new->redirector.dest = -1;
	new->redirector.filename = NULL;
	new->here_doc_eof = here_doc_eof;
	new->next = next;
	return (new);
}

void	redirect_destroy_all(t_redirect *redirect)
{
	t_redirect	*cur;
	t_redirect	*next;

	cur = redirect;
	while (cur != NULL)
	{
		next = cur->next;
		if (cur->here_doc_eof != NULL)
		{
			free(cur->here_doc_eof);
			unlink(cur->redirector.filename);
		}
		if (cur->redirectee.filename != NULL)
			free(cur->redirectee.filename);
		if (cur->redirector.filename != NULL)
			free(cur->redirector.filename);
		free(cur);
		cur = next;
	}
}

void	redirect_add_to_last(t_minishell *shell, t_redirect **head,
		t_redirect *new)
{
	t_redirect	*cur;

	if (new == NULL)
		return ;
	cur = *head;
	expand_filename(shell, &new->redirectee.filename);
	expand_filename(shell, &new->redirector.filename);
	if (cur == NULL)
	{
		*head = new;
		return ;
	}
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = new;
}
