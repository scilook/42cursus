/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonhwki <geonhwki@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 00:30:55 by geonhwki          #+#    #+#             */
/*   Updated: 2025/01/09 17:21:59 by geonhwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

static char	*ft_strchr(char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (str);
		++str;
	}
	return (NULL);
}

static void	read_line(int fd, char **saved)
{
	int		size;
	char	*temp;
	char	*buffer;

	while (*saved == NULL || ft_strchr(*saved, '\n') == NULL)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return ;
		size = read(fd, buffer, BUFFER_SIZE);
		if (size <= 0)
		{
			free(buffer);
			return ;
		}
		buffer[size] = '\0';
		temp = *saved;
		*saved = ft_strjoin(*saved, buffer);
		free(temp);
		free(buffer);
	}
}

char	*get_next_line(int fd)
{
	static char	*saved = NULL;
	char		*result;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	read_line(fd, &saved);
	if (saved == NULL)
		return (NULL);
	if (*saved == '\0')
	{
		free(saved);
		saved = NULL;
		return (NULL);
	}
	result = gnl_strdup(saved, true);
	if (result == NULL)
		return (NULL);
	if (ft_strchr(saved, '\n') != NULL)
		temp = gnl_strdup(ft_strchr(saved, '\n') + 1, false);
	else
		temp = NULL;
	free(saved);
	saved = temp;
	return (result);
}
