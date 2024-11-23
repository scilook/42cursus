/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:24:02 by hyeson            #+#    #+#             */
/*   Updated: 2024/11/23 15:17:47 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


size_t	buf_check(char *buf, size_t buf_cnt)
{
	if (buf == NULL)
		return (BUFFER_SIZE);
	while (*(buf + buf_cnt) != '\0')
	{
		if (*(buf + buf_cnt) == '\n')
			break ;
		buf_cnt++;
	}
	return (buf_cnt);
}

char	*get_next_line(int fd)
{
	static char	*remain_buf;
	char		*main_buf;
	char		*tmp;
	char		buf[BUFFER_SIZE + 1];
	size_t		cnt;

	if (ft_strlen(remain_buf) == buf_check(remain_buf, 0))
		cnt = BUFFER_SIZE;
	else
	{
		main_buf = ft_substr(remain_buf, 0, buf_check(remain_buf, 0));
		remain_buf = remain_buf + buf_check(remain_buf, 0) + 1;
	}
	buf[BUFFER_SIZE] = '\0';
	while (cnt == BUFFER_SIZE)
	{
		if (read(fd, buf, BUFFER_SIZE) <= 0)
			return (NULL);
		cnt = buf_check(buf, 0);
		tmp = ft_substr(buf, 0, cnt);
		main_buf = ft_strjoin(main_buf, tmp);
		free(tmp);
		remain_buf = buf + cnt + 1;
	}
	return (main_buf);
}

/* 문제점: EOF에서 \n의 출력, 메모리 누수, 없는 파일의 대응 미비 */