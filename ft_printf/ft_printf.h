/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:02:49 by hyeson            #+#    #+#             */
/*   Updated: 2024/11/24 18:24:59 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putchar_fd(char c, int fd, size_t *cnt);
void	vaprintf(va_list ap, const char c, size_t *cnt);
int		ft_printf(const char *s, ...)__attribute__((format(printf, 1, 2)));

#endif /* FT_PRINTF_H */