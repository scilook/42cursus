/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:02:49 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/25 07:27:57 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

void	vaprintf(va_list ap, const char c, size_t *cnt);
int		ft_printf(const char *s, ...)__attribute__((format(printf, 1, 2)));

#endif /* FT_PRINTF_H */