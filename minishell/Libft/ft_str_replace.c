/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 21:46:51 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/16 23:02:23 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include <stdlib.h>

static char	*_ndup(char *str, size_t n)
{
	char	*new;

	if (n == 0)
		return (ft_strdup(""));
	new = ft_malloc(n + 1);
	ft_strlcpy(new, str, n + 1);
	return (new);
}

char	*ft_str_replace_range(char *str, char *start, char *end,
		char *replacement)
{
	char	*result;
	char	*tmp;
	size_t	prefix_len;
	size_t	suffix_len;

	prefix_len = start - str;
	start = _ndup(str, prefix_len);
	suffix_len = ft_strlen(end);
	end = ft_strdup(end);
	result = ft_strjoin(start, replacement);
	free(start);
	tmp = result;
	result = ft_strjoin(result, end);
	free(tmp);
	free(end);
	return (result);
}
