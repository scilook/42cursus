/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:29:13 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/16 23:02:24 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;
	unsigned int	length;

	length = ft_strlen(s);
	result = malloc(length + 1);
	if (result == NULL)
		return (NULL);
	i = -1;
	while (++i < length)
		result[i] = f(i, s[i]);
	result[i] = '\0';
	return (result);
}
