/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:22:18 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/15 18:25:22 by hyeson           ###   ########.fr       */
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
	mlx_loop_hook(set.mlx, map_parse, &set);
	mlx_loop(set.mlx);
	return (0);
}
