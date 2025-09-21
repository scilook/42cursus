/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:21:36 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/16 23:02:29 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include <stdlib.h>
#include <unistd.h>

void	*ft_malloc(size_t size)
{
	void	*memory;

	memory = malloc(size);
	if (memory == NULL)
	{
		write(2, "Malloc Failed", 13);
		exit(1);
	}
	return (memory);
}

t_bool	ft_isdigits(const char *str)
{
	if (str == NULL)
		return (FALSE);
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (FALSE);
		++str;
	}
	return (TRUE);
}

char	*ft_strndup(const char *str, size_t n)
{
	char	*new;

	if (n == 0)
		return (ft_strdup(""));
	new = ft_malloc(n + 1);
	ft_memcpy(new, str, n);
	new[n] = 0;
	return (new);
}

t_bool	ft_is_varname(const char chr)
{
	return (ft_isalnum(chr) || chr == '_');
}
