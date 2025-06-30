/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:15:53 by geonhwki          #+#    #+#             */
/*   Updated: 2024/10/09 06:08:25 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	char	*substr;
	size_t	sublen;

	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	substr = (char *)s + start;
	sublen = min(len, ft_strlen(substr));
	result = malloc(sublen + 1);
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, substr, sublen);
	result[sublen] = '\0';
	return (result);
}
