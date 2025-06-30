/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 00:30:59 by geonhwki          #+#    #+#             */
/*   Updated: 2024/12/12 04:07:34 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

size_t	gnl_strlen(const char *str, bool stop_at_newline)
{
	const char	*s;

	if (str == NULL)
		return (0);
	s = str;
	while (*s != '\0' && !(*s == '\n' && stop_at_newline))
		s++;
	return (s - str);
}

char	*gnl_strdup(const char *s, bool stop_at_newline)
{
	char	*dest;
	size_t	size;

	size = gnl_strlen(s, stop_at_newline) + 1;
	dest = malloc(size + 1);
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s, size);
	dest[size] = '\0';
	return (dest);
}

void	*ft_memcpy(void *dest0, const void *src0, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*src;

	dest = dest0;
	src = src0;
	while (n--)
		*dest++ = *src++;
	return (dest0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = gnl_strlen(s1, false);
	s2_len = gnl_strlen(s2, false);
	result = malloc(s1_len + s2_len + 1);
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, s1, s1_len);
	ft_memcpy(result + s1_len, s2, s2_len + 1);
	return (result);
}
