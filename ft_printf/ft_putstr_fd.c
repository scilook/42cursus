/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:29:20 by hyeson            #+#    #+#             */
/*   Updated: 2024/10/30 19:23:09 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd, size_t *cnt)
{
	if (s == NULL)
		s = "(null)";
	write(fd, s, ft_strlen(s));
	*cnt += ft_strlen(s);
}
