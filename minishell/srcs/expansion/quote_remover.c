/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_remover.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:06:23 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/17 00:42:01 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

void	_remove_quote_internal(char *old, char *new, char quote)
{
	while (*old != '\0')
	{
		if (*old == '\\')
		{
			if (quote == 0 || (quote == '"' && ft_strchr("\\\"$", old[1])))
				old += 1;
			*new ++ = *old++;
		}
		else if (quote != 0)
		{
			if (*old == quote)
				old++;
			else
				*new ++ = *old++;
		}
		else if (*old == '"' || *old == '\'')
			quote = *old++;
		else
			*new ++ = *old++;
	}
	*new = '\0';
}

void	remove_quote(char **str_ptr)
{
	char	*old;
	char	*new;
	char	quote;

	old = *str_ptr;
	new = ft_malloc((ft_strlen(old) + 1));
	quote = 0;
	_remove_quote_internal(old, new, quote);
	free(*str_ptr);
	*str_ptr = new;
}
