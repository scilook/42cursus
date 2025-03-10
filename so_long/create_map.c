/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:55:50 by hyeson            #+#    #+#             */
/*   Updated: 2025/02/03 15:59:21 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	if_ret(char bool)
{
	if (bool)
	{
		write(STDOUT_FILENO, "ERROR\n", 7);
		exit(0);
	}
}

static char	*read_line(int fd)
{
	char	buf[1025];
	char	*line;
	ssize_t	size;

	size = 1;
	line = NULL;
	while (size > 0)
	{
		size = read(fd, buf, 1024);
		if (size < 0)
			return (NULL);
		buf[size] = '\0';
		if (line == NULL)
		{
			line = (char *)malloc(sizeof(char) * 1);
			if (line == NULL)
				return (NULL);
			*line = '\0';
		}
		line = ft_strjoin(line, buf);
		if (line == NULL)
			return (NULL);
	}
	return (line);
}

void	valid_check(char **map)
{
	t_point	point;
	size_t	size;
	char	collectible;
	char	exit;
	char	player;

	point.x = 0;
	point.y = 0;
	collectible = 0;
	exit = 0;
	player = 0;
	size = ft_strlen(map[0]);
	while (map[0][point.y])
	{
		if_ret(map[0][point.y] != '1');
		point.y++;
	}
	while (map[point.x])
	{
		point.y = 0;
		while (map[point.x][point.y])
		{
			if (map[point.x][point.y] == 'C')
				collectible++;
			if (map[point.x][point.y] == 'E')
				exit++;
			if (map[point.x][point.y] == 'P')
				player++;
			point.y++;
		}
		point.x++;
	}
	if_ret(!(collectible > 0 && exit == 1 && player == 1));
	point.y == 0;
	while (map[point.x - 1][point.y])
	{
		if_ret(map[point.x - 1][point.y] != '1');
		point.y++;
	}
}

char	**create_map(char *argv)
{
	char	*line;
	char	**map;
	int		fd;

	fd = open(argv, O_RDONLY);
	line = read_line(fd);
	map = ft_split(line, '\n');
	free(line);
	valid_check(map);
	return (map);
}
