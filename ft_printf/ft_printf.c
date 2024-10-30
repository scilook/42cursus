/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:00:23 by hyeson            #+#    #+#             */
/*   Updated: 2024/10/30 12:07:35 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_in_set(char *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_printf(const char *s, ...)
{
	size_t	i;
	size_t	cnt;
	va_list	ap;

	cnt = 0;
	va_start(ap, s);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			if (find_in_set("cspdiuxX%%", s[i]) == -1)
				return (-1);
			vaprintf(i, ap, s, &cnt);
			i++;
			continue ;
		}
		ft_putchar_fd(s[i], 1);
		cnt++;
		i++;
	}
	va_end(ap);
	return (cnt);
}
