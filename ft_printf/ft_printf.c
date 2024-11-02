/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:00:23 by hyeson            #+#    #+#             */
/*   Updated: 2024/11/02 13:36:48 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	size_t	i;
	size_t	cnt;
	size_t	iserror;
	va_list	ap;

	if (s == NULL)
		return(-1);
	cnt = 0;
	va_start(ap, s);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%' && ++i)
		{
			iserror = vaprintf(ap, s[i++], &cnt);
			continue ;
		}
		ft_putchar_fd(s[i++], 1, &cnt);
	}
	va_end(ap);
	if (iserror == 1)
		return (-1);
	else
		return (cnt);
}
