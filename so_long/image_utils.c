/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:06:43 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/14 10:13:42 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	if_ret(char bool)
{
	if (bool)
	{
		write(STDOUT_FILENO, "ERROR!\n", 7);
		exit(0);
	}
}

void	image_align(void *mlx, t_set *set)
{
	int	w;
	int	h;

	set->col = mlx_xpm_file_to_image(mlx, "./set/col.xpm", &w, &h);
	set->empty = mlx_xpm_file_to_image(mlx, "./set/empty.xpm", &w, &h);
	set->exit = mlx_xpm_file_to_image(mlx, "./set/exit.xpm", &w, &h);
	set->player = mlx_xpm_file_to_image(mlx, "./set/player.xpm", &w, &h);
	set->wall = mlx_xpm_file_to_image(mlx, "./set/wall.xpm", &w, &h);
}

