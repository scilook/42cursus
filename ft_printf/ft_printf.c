/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:00:23 by hyeson            #+#    #+#             */
/*   Updated: 2024/11/07 15:11:32 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	size_t	i;
	size_t	cnt;
	va_list	ap;

	if (s == NULL)
		return (-1);
	cnt = 0;
	va_start(ap, s);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%' && ++i)
		{
			while (s[i] == ' ')
				i++;
			if (s[i] == '\0')
				return (-1);
			vaprintf(ap, s[i - 1], s[i], &cnt);
			i++;
			continue ;
		}
		ft_putchar_fd(s[i++], 1, &cnt);
	}
	va_end(ap);
	return (cnt);
}
