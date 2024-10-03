/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:59:34 by hyeson            #+#    #+#             */
/*   Updated: 2024/10/03 10:49:50 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	slen;
	size_t	i;

	slen = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * slen);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < slen)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
