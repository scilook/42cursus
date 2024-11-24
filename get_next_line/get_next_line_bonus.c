/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:24:02 by hyeson            #+#    #+#             */
/*   Updated: 2024/11/24 18:55:02 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	buf_check(char *buf)
{
	size_t	i;

	i = 0;
	while (*(buf + i) != '\0')
	{
		if (*(buf + i) == '\n')
		{
			return (i);
		}
		i++;
	}
	return (i);
}

char	*line_feed(char *remain)
{
	char	*line;
	size_t	i;
	size_t	size;

	size = buf_check(remain);
	line = (char *)malloc(sizeof(char) * (ft_strlen(remain) - size + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	if (*remain != '\0')
		ft_strcpy(line, remain + size + 1);
	free(remain);
	return (line);
}

char	*get_line(char *remain)
{
	char	*line;
	size_t	i;
	size_t	size;

	size = buf_check(remain);
	line = (char *)malloc(sizeof(char) * (size + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (i != size)
	{
		line[i] = remain[i];
		i++;
	}
	if (remain[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_line(int fd, char *remain)
{
	char	buf[BUFFER_SIZE + 1];
	char	*line;
	ssize_t	size;

	size = 1;
	line = remain;
	while (ft_strchr(line, '\n') == NULL && size > 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size <= 0)
			return (NULL);
		buf[size] = '\0';
		line = ft_strjoin(line, buf);
		if (line == NULL)
			return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remain;
	char		*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (remain == NULL)
	{
		remain = (char *)malloc(sizeof(char) * 1);
		if (remain == NULL)
			return (NULL);
		*remain = '\0';
	}
	tmp = read_line(fd, remain);
	if (tmp == NULL)
	{
		free(remain);
		remain = tmp;
		return (NULL);
	}
	remain = tmp;
	line = get_line(remain);
	remain = line_feed(remain);
	return (line);
}
