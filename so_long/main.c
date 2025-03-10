/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:22:18 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/10 14:03:07 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cal_trgb(int t, int r, int g, int b)
{
	if ((t | r | g | b | 0xFF) == 0xFF)
		return (t << 24 | r << 16 | g << 8 | b);
	return (0);
}

int	key_hook(int keycode, t_point *player)
{
	printf("code:%d!\n", keycode);
	if (keycode == 65307)
		exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_var	vars;
	t_set	*set;
	t_point	point;
	char	**map;

	if_ret(argc != 2);
	vars.mlx = mlx_init();
	map = create_map(argv[1]);
	point.y = 0;
	point.x = 0;
	while (map[point.y])
		point.y++;
	while (map[0][point.x])
		point.x++;
	vars.win = mlx_new_window(vars.mlx, 64 * \
	(point.x + 1), 64 * (point.y + 1), "TEST");
	image_align(vars.mlx, set);
	map_parse(set, map, vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
