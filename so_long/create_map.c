/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:55:50 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/24 17:12:24 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*line_init(char *line)
{
	if (line == NULL)
	{
		line = (char *)malloc(sizeof(char) * 1);
		if (line == NULL)
			return (NULL);
		*line = '\0';
	}
	return (line);
}

static char	*read_line(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	char	*line;
	char	*tmp;
	ssize_t	size;

	size = 1;
	line = NULL;
	while (size > 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size < 0)
			return (NULL);
		buf[size] = '\0';
		line = line_init(line);
		tmp = line;
		line = ft_strjoin(line, buf);
		free(tmp);
		if (line == NULL)
			return (NULL);
	}
	return (line);
}

static void	edge_check(t_set *set)
{
	size_t	line_length;
	size_t	i;

	line_length = ft_strlen(set->map[0]);
	i = 0;
	while (set->map[i])
	{
		if_ret(ft_strlen(set->map[i]) != line_length, set);
		if_ret(set->map[i][set->x - 1] != '1', set);
		if_ret(set->map[i][0] != '1', set);
		i++;
	}
	i = 0;
	while (i < line_length)
	{
		if_ret(set->map[0][i] != '1', set);
		if_ret(set->map[set->y - 1][i] != '1', set);
		i++;
	}
}

static void	valid_check(t_set *set)
{
	set->y = 0;
	while (set->map[set->y])
	{
		set->x = 0;
		while (set->map[set->y][set->x])
		{
			if (set->map[set->y][set->x] == 'C')
				set->c++;
			if (set->map[set->y][set->x] == 'E')
				set->e++;
			if (set->map[set->y][set->x] == 'P')
			{
				set->p++;
				set->p_y = set->y;
				set->p_x = set->x;
			}
			set->x++;
		}
		set->y++;
	}
	if_ret(!(set->c > 0 && set->e == 1 && set->p == 1), set);
}

void	create_map(char *argv, t_set *set)
{
	char	*line;
	int		fd;
	int		x;
	int		y;

	fd = open(argv, O_RDONLY);
	line = read_line(fd);
	close(fd);
	set->map = ft_split(line, '\n');
	free(line);
	valid_check(set);
	edge_check(set);
	condition_check(set);
	mlx_get_screen_size(set->mlx, &x, &y);
	if (x < set->x * 64 || y < set->y * 64)
		if_ret(1, set);
}
