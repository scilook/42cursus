/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:56:46 by geonhwki          #+#    #+#             */
/*   Updated: 2024/10/16 22:36:42 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

static int	ft_print_str(const char *str)
{
	int	length;

	length = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (*str != '\0')
		length += write(1, str++, 1);
	return (length);
}

static int	handle_format_specifier(char c, va_list *ap)
{
	int	length;

	length = 0;
	if (c == 'x')
		ft_putunbr_base(va_arg(*ap, unsigned int), "0123456789abcdef", &length);
	else if (c == 'X')
		ft_putunbr_base(va_arg(*ap, unsigned int), "0123456789ABCDEF", &length);
	else if (c == 'u')
		ft_putunbr_base(va_arg(*ap, unsigned int), "0123456789", &length);
	else if (c == 'p')
		ft_putptr(va_arg(*ap, size_t), &length);
	else if (c == 's')
		length = ft_print_str(va_arg(*ap, char *));
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(*ap, int), &length);
	else if (c == '%')
		length = ft_print_char('%');
	else if (c == 'c')
		length = ft_print_char(va_arg(*ap, int));
	else
		return (0);
	return (length);
}

static int	_ft_printf(const char *str, va_list *ap)
{
	int	length;

	length = 0;
	while (*str != '\0')
	{
		if (*str == '%')
			length += handle_format_specifier(*++str, ap);
		else
			length += ft_print_char(*str);
		++str;
	}
	return (length);
}

int	ft_printf(const char *str, ...)
{
	int		length;
	va_list	ap;

	va_start(ap, str);
	length = _ft_printf(str, &ap);
	va_end(ap);
	return (length);
}
