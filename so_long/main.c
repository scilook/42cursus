/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:22:18 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/23 13:55:54 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_set	set;

	set.c = 0;
	set.e = 0;
	set.p = 0;
	if (argc != 2)
	{
		write(1, "ERROR\n", 7);
		return (0);
	}
	set.mlx = mlx_init();
	image_align(&set);
	create_map(argv[1], &set);
	set.win = mlx_new_window(set.mlx, 64 * set.x, 64 * set.y, argv[0]);
	mlx_key_hook(set.win, key_control_hook, &set);
	//mlx_hook(set.win, mouse_hook, &set);
	mlx_loop_hook(set.mlx, map_parse, &set);
	mlx_hook(set.win, 17, 0, mlx_loop_end, set.mlx);
	mlx_loop(set.mlx);
	destroy_win(&set);
	mlx_destroy_window(set.mlx, set.win);
	mlx_destroy_display(set.mlx);
	return (0);
}

