/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:25:44 by hyeson            #+#    #+#             */
/*   Updated: 2024/11/24 18:59:16 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif /* BUFFER_SIZE */

# include <unistd.h>
# include <malloc.h>

size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strcpy(char *dest, char const *src);
char	*get_next_line(int fd);

#endif /* GET_NEXT_LINE_BONUS_H */
