/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:15:47 by hyeson            #+#    #+#             */
/*   Updated: 2025/01/26 17:37:57 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_parse(t_set *set, char **map, t_var vars)
{
	t_point	p;

	p.y = 0;
	while (map[p.y])
	{
		p.x = 0;
		while (map[p.y][p.x])
		{
			convert2image(map, p, set, vars);
			p.x++;
		}
		p.y++;
	}
}

void	convert2image(char **map, t_point p, t_set *set, t_var v)
{
	if (map[p.y][p.x] == 'C')
		mlx_put_image_to_window(v.mlx, v.win, set->col, 64 * p.x, 64 * p.y);
	else if (map[p.y][p.x] == '0')
		mlx_put_image_to_window(v.mlx, v.win, set->empty, 64 * p.x, 64 * p.y);
	else if (map[p.y][p.x] == 'E')
		mlx_put_image_to_window(v.mlx, v.win, set->exit, 64 * p.x, 64 * p.y);
	else if (map[p.y][p.x] == 'P')
		mlx_put_image_to_window(v.mlx, v.win, set->player, 64 * p.x, 64 * p.y);
	else if (map[p.y][p.x] == '1')
		mlx_put_image_to_window(v.mlx, v.win, set->wall, 64 * p.x, 64 * p.y);
	else
		if_ret(1);
}
