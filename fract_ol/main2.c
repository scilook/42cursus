/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:22:18 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/13 11:00:00 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_var
{
	void	*mlx;
	void	*win;
}	t_var;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int	cal_trgb(int t, int r, int g, int b)
{
	if (t | r | g | b | 0xFF == 0xFF)
		return (t << 24 | r << 16 | g << 8 | b);
	return (0);
}

int	key_hook(int keycode, t_var *vars)
{
	printf("code:%d!\n", keycode);
	if (keycode == 65307)
		exit(0);
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	printf("mcode:%d!%d!%d!\n", button, x, y);
}

int	main(void)
{
	t_data	img;
	t_var	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 600, 400, "TEST");
	img.img = mlx_new_image(vars.mlx, 600, 400);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	for (int i = 0 ; i < 600 ; i++)
			for (int j = 0 ; j < 400 ; j++)
				my_mlx_pixel_put(&img, i, j, cal_trgb(i * j, 0, 0, 0));
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 06, 0, mouse_hook, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	// mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
