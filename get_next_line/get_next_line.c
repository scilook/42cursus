/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:24:02 by hyeson            #+#    #+#             */
/*   Updated: 2024/11/25 16:25:11 by hyeson           ###   ########.fr       */
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
	size_t	size;

	size = buf_check(remain);
	if (size == ft_strlen(remain))
	{
		free(remain);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (ft_strlen(remain) - size + 1));
	if (line == NULL)
		return (NULL);
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
		if (size < 0)
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
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	remain = read_line(fd, remain);
	if (remain == NULL)
		return (NULL);
	line = get_line(remain);
	remain = line_feed(remain);
	if (*line == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
