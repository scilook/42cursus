/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:24:02 by hyeson            #+#    #+#             */
/*   Updated: 2024/11/15 20:20:54 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>


/* remain_buf에  \n이 있을 가능성 존재 */
char	*get_next_line(int fd)
{
	static char	*remain_buf;
	char		*main_buf;
	char		*buf;
	size_t		bufcnt;

	main_buf = remain_buf;
	bufcnt = BUFFER_SIZE;
	while (bufcnt == BUFFER_SIZE)
	{
		buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (buf == NULL)
			return (NULL);
		read(fd, buf, BUFFER_SIZE);
		*(buf + BUFFER_SIZE) = '\0';
		bufcnt = 0;
		while (bufcnt < BUFFER_SIZE)
		{
			if (*(buf + bufcnt) == '\n')
			{
				remain_buf = buf + bufcnt + 1;
				*(buf + bufcnt) = '\0';
				break ;
			}
			bufcnt++;
		}
		main_buf = ft_strjoin(main_buf, buf);
		free(buf);
	}
	return (main_buf);
}
