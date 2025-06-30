/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 00:30:52 by geonhwki          #+#    #+#             */
/*   Updated: 2025/01/07 16:54:02 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif /* BUFFER_SIZE */

# include <stdbool.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*gnl_strdup(const char *s, bool stop_at_newline);
size_t	gnl_strlen(const char *str, bool stop_at_newline);
void	*ft_memcpy(void *dest0, const void *src0, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);

#endif /* GET_NEXT_LINE_H */
