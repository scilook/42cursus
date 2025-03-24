/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:06:43 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/24 17:20:28 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_destroy(t_set *set)
{
	mlx_destroy_image(set->mlx, set->col);
	mlx_destroy_image(set->mlx, set->empty);
	mlx_destroy_image(set->mlx, set->exit);
	mlx_destroy_image(set->mlx, set->player);
	mlx_destroy_image(set->mlx, set->wall);
}

void	destroy_win(t_set *set)
{
	size_t	i;

	i = 0;
	while (set->map[i])
	{
		free(set->map[i]);
		i++;
	}
	free(set->map);
	image_destroy(set);
}

void	if_ret(int bool, t_set *set)
{
	if (bool)
	{
		write(1, "ERROR\n", 7);
		destroy_win(set);
		mlx_destroy_display(set->mlx);
		free(set->mlx);
		exit(0);
	}
}

void	image_align(t_set *set)
{
	int	w;
	int	h;

	set->col = mlx_xpm_file_to_image(set->mlx, "./set/col.xpm", &w, &h);
	set->empty = mlx_xpm_file_to_image(set->mlx, "./set/empty.xpm", &w, &h);
	set->exit = mlx_xpm_file_to_image(set->mlx, "./set/exit.xpm", &w, &h);
	set->player = mlx_xpm_file_to_image(set->mlx, "./set/player.xpm", &w, &h);
	set->wall = mlx_xpm_file_to_image(set->mlx, "./set/wall.xpm", &w, &h);
}
