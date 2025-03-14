/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:22:18 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/14 11:48:03 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_control_hook(int keycode, t_var *vars, int x, int y, int z)
{
	y = 0;
	x = 0;
	z = 1;
	printf("code:%d\n", keycode);
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'P')
				break ;
			x++;
		}
		if (vars->map[y][x] == 'P')
			break ;
		y++;
	}
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		while (vars->map[y])
			free(vars->map[y]);
		free(vars->map);
	}
	if (keycode == 65361 && vars->map[y][x - 1] != '1')
	{
		vars->map[y][x] = '0';
		vars->map[y][x - 1] = 'P';
	}
	if (keycode == 65362 && vars->map[y - 1][x] != '1')
	{
		vars->map[y][x] = '0';
		vars->map[y - 1][x] = 'P';
	}
	if (keycode == 65363 && vars->map[y][x + 1] != '1')
	{
		vars->map[y][x] = '0';
		vars->map[y][x + 1] = 'P';
	}
	if (keycode == 65364 && vars->map[y + 1][x] != '1')
	{
		vars->map[y][x] = '0';
		vars->map[y + 1][x] = 'P';
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_var	vars;
	t_set	set;
	t_point	point;
	t_point	p2;
	t_sets	sets;

	sets.point = &point;
	sets.var = &vars;
	sets.set = &set;
	if_ret(argc != 2);
	vars.mlx = mlx_init();
	vars.map = create_map(argv[1]);
	point.y = 0;
	point.x = 0;
	while (vars.map[point.y])
		point.y++;
	while (vars.map[0][point.x])
		point.x++;
	mlx_get_screen_size(vars.mlx, &p2.x, &p2.y);
	if_ret(point.x * 64 > p2.x || point.y * 64 > p2.y);
	vars.win = mlx_new_window(vars.mlx, 64 * point.x, 64 * point.y, argv[0]);
	image_align(vars.mlx, &set);
	mlx_key_hook(vars.win, key_control_hook, &vars);
	mlx_loop_hook(vars.mlx, map_parse, &sets);
	mlx_loop(vars.mlx);
	return (0);
}
