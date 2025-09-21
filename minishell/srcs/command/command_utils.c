/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:33:53 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/16 23:02:27 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

int	command_get_pipe_count(t_command *self)
{
	int			size;
	t_command	*cur;

	size = 0;
	cur = self->pipe;
	while (cur != NULL)
	{
		cur = cur->pipe;
		++size;
	}
	return (size);
}
