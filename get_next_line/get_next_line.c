/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:24:02 by hyeson            #+#    #+#             */
/*   Updated: 2024/11/23 15:42:43 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


ssize_t	buf_check(char *buf, size_t buf_cnt)
{
	if (buf == NULL)
		return (-1);
	while (*(buf + buf_cnt) != '\0')
	{
		if (*(buf + buf_cnt) == '\n')
		{
			return (buf_cnt);
		}
		buf_cnt++;
	}
	return (buf_cnt);
}

char	*get_next_line(int fd)
{
	static char	*remain_buf;
	char		*main_buf;
	char		buf[BUFFER_SIZE + 1];
	size_t		buf_cnt;
	ssize_t		sob;

	if (ft_strlen(remain_buf) == buf_check(remain_buf, 0))
		buf_cnt = BUFFER_SIZE;
	else
		buf_cnt = ft_strlen(remain_buf);
	main_buf = ft_substr(remain_buf, 0, buf_check(remain_buf, 0));
	remain_buf = remain_buf + buf_cnt + 1;
	while (buf_cnt == BUFFER_SIZE)
	{
		sob = read(fd, buf, BUFFER_SIZE);
		*(buf + BUFFER_SIZE) = '\0';
		buf_cnt = buf_check(buf, 0);
		remain_buf = buf + buf_cnt + 1;
		ft_strjoin(main_buf, buf);
	}
	if (sob <= 0)
		return (NULL);
	return (main_buf);
}

/* 문제점: EOF에서 \n의 출력, 메모리 누수, 없는 파일의 대응 미비 */