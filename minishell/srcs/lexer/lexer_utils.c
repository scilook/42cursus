/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 22:57:57 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/16 23:02:28 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_bool	_lexer_is_at_end(t_scanner *self)
{
	return (*self->current == '\0' || *self->current == '\n');
}

t_bool	_lexer_is_start_of_operator(char c)
{
	if (c == '<')
		return (TRUE);
	if (c == '>')
		return (TRUE);
	if (c == '&')
		return (TRUE);
	if (c == '|')
		return (TRUE);
	return (FALSE);
}
