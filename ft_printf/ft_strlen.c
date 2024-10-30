/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:26:39 by hyeson            #+#    #+#             */
/*   Updated: 2024/10/30 20:19:15 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	if (s == NULL)
		return (0);
	cnt = 0;
	while (*(s + cnt))
	{
		cnt++;
	}
	return (cnt);
}
