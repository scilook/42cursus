/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:24:38 by geonhwki          #+#    #+#             */
/*   Updated: 2024/10/05 19:07:33 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*head;
	char	*tail;
	size_t	length;
	char	*result;

	head = (char *)s1;
	tail = (char *)s1 + ft_strlen(s1) - 1;
	while (*head != '\0' && ft_strchr(set, *head) != NULL)
		++head;
	while (tail > head && ft_strchr(set, *tail) != NULL)
		--tail;
	length = tail - head + 1;
	result = malloc(length + 1);
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, head, length);
	result[length] = '\0';
	return (result);
}
