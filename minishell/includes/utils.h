/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 19:02:48 by geonhwki          #+#    #+#             */
/*   Updated: 2025/09/16 23:02:26 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}		t_bool;

void	*ft_malloc(size_t size);
t_bool	ft_isdigits(const char *str);
char	*ft_strndup(const char *str, size_t n);
t_bool	ft_is_varname(const char chr);

#endif /* UTILS_H */
