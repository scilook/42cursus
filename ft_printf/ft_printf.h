/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:02:49 by hyeson            #+#    #+#             */
/*   Updated: 2024/10/30 10:30:29 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_F
# define FT_PRINT_F

# define ABS(value) ((value)*((value > 0) - (value < 0)))
# include <stdarg.h>
# include <malloc.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd, size_t *cnt);
void	vaprintf(size_t *i, va_list ap, const char *s, size_t *cnt);
int		ft_printf(const char *, ...);

#endif /* FT_PRINT_F */