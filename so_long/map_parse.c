/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:15:47 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/24 17:12:54 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	convert2image(t_set *set)
{
	if (set->map[set->y][set->x] == 'C')
		mlx_put_image_to_window(set->mlx, set->win, \
		set->col, 64 * set->x, 64 * set->y);
	else if (set->map[set->y][set->x] == '0')
		mlx_put_image_to_window(set->mlx, set->win, \
		set->empty, 64 * set->x, 64 * set->y);
	else if (set->map[set->y][set->x] == 'E')
		mlx_put_image_to_window(set->mlx, set->win, \
		set->exit, 64 * set->x, 64 * set->y);
	else if (set->map[set->y][set->x] == 'P')
		mlx_put_image_to_window(set->mlx, set->win, \
		set->player, 64 * set->x, 64 * set->y);
	else if (set->map[set->y][set->x] == '1')
		mlx_put_image_to_window(set->mlx, set->win, \
		set->wall, 64 * set->x, 64 * set->y);
	else
		if_ret(1, set);
}

int	map_parse(t_set *set)
{
	set->y = 0;
	while (set->map[set->y])
	{
		set->x = 0;
		while (set->map[set->y][set->x])
		{
			convert2image(set);
			set->x++;
		}
		set->y++;
	}
	return (0);
}
