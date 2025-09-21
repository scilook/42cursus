/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:10:17 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/16 23:02:27 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "redirect.h"
#include "utils.h"
#include <stdlib.h>

static void	command_destroy(t_command *self)
{
	t_command	*cur;
	t_command	*next;

	cur = self;
	while (cur != NULL)
	{
		next = cur->pipe;
		redirect_destroy_all(cur->redirects);
		word_destroy_all(cur->words);
		free(cur);
		cur = next;
	}
}

t_command	*command_init(void)
{
	t_command	*command;

	command = ft_malloc(sizeof(t_command));
	command->next = NULL;
	command->pipe = NULL;
	command->redirects = NULL;
	command->words = NULL;
	return (command);
}

void	command_destroy_all(t_command *self)
{
	t_command	*cur;
	t_command	*next;

	cur = self;
	while (cur != NULL)
	{
		next = cur->next;
		command_destroy(cur);
		cur = next;
	}
}
