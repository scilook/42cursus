/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:15:47 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/12 16:59:17 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_parse(t_set *set, t_var vars)
{
	t_point	p;

	p.y = 0;
	while (vars.map[p.y])
	{
		p.x = 0;
		while (vars.map[p.y][p.x])
		{
			convert2image(p, set, vars);
			p.x++;
		}
		p.y++;
	}
}

void	convert2image(t_point p, t_set *set, t_var v)
{
	if (v.map[p.y][p.x] == 'C')
	{
		mlx_put_image_to_window(v.mlx, v.win, set->empty, 64 * p.x, 64 * p.y);
		mlx_put_image_to_window(v.mlx, v.win, set->col, 64 * p.x, 64 * p.y);
	}
	else if (v.map[p.y][p.x] == '0')
		mlx_put_image_to_window(v.mlx, v.win, set->empty, 64 * p.x, 64 * p.y);
	else if (v.map[p.y][p.x] == 'E')
		mlx_put_image_to_window(v.mlx, v.win, set->exit, 64 * p.x, 64 * p.y);
	else if (v.map[p.y][p.x] == 'P')
	{	
		mlx_put_image_to_window(v.mlx, v.win, set->empty, 64 * p.x, 64 * p.y);
		mlx_put_image_to_window(v.mlx, v.win, set->player, 64 * p.x, 64 * p.y);
	}
	else if (v.map[p.y][p.x] == '1')
		mlx_put_image_to_window(v.mlx, v.win, set->wall, 64 * p.x, 64 * p.y);
	else
		if_ret(1);
}
