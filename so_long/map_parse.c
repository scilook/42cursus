/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:15:47 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/14 10:19:26 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_parse(t_sets *sets)
{
	t_point	p;

	p.y = 0;
	while (sets->var->map[p.y])
	{
		p.x = 0;
		while (sets->var->map[p.y][p.x])
		{
			printf("%c ", sets->var->map[p.y][p.x]);
			convert2image(p, *sets);
			p.x++;
		}
		printf("\n");
		p.y++;
	}
}

void	convert2image(t_point p, t_sets s)
{
	if (s.var->map[p.y][p.x] == 'C')
		mlx_put_image_to_window(s.var->mlx, s.var->win, \
		s.set->col, 64 * p.x, 64 * p.y);
	else if (s.var->map[p.y][p.x] == '0')
		mlx_put_image_to_window(s.var->mlx, s.var->win, \
		s.set->empty, 64 * p.x, 64 * p.y);
	else if (s.var->map[p.y][p.x] == 'E')
		mlx_put_image_to_window(s.var->mlx, s.var->win, \
		s.set->exit, 64 * p.x, 64 * p.y);
	else if (s.var->map[p.y][p.x] == 'P')
		mlx_put_image_to_window(s.var->mlx, s.var->win, \
		s.set->player, 64 * p.x, 64 * p.y);
	else if (s.var->map[p.y][p.x] == '1')
		mlx_put_image_to_window(s.var->mlx, s.var->win, \
		s.set->wall, 64 * p.x, 64 * p.y);
	else
		if_ret(1);
}
