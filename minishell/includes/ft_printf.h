/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:56:00 by geonhwki          #+#    #+#             */
/*   Updated: 2024/10/16 22:36:39 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_putunbr_base(unsigned int nb, const char *base, int *out_length);
void	ft_putulnbr_base(size_t nb, const char *base, int *out_length);
void	ft_putnbr(int nb, int *out_length);
void	ft_putptr(size_t nb, int *out_length);

#endif /* FT_PRINTF_H */
