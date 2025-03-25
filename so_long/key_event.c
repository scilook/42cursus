/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:02:56 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/25 10:26:50 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	key_left(int keycode, t_set *set, int i)
{
	if (set->map[set->p_y][set->p_x - 1] != '1')
	{
		if (!(set->c != 0 && set->map[set->p_y][set->p_x - 1] == 'E'))
		{
			if (keycode == 65361 || keycode == 'a')
			{
				ft_printf("%d\n", ++i);
				if (set->map[set->p_y][set->p_x - 1] == 'C')
					set->c--;
				if (set->map[set->p_y][set->p_x - 1] == 'E')
					set->e--;
				set->map[set->p_y][set->p_x] = '0';
				set->map[set->p_y][--set->p_x] = 'P';
				return (1);
			}
		}
	}
	return (0);
}

static int	key_up(int keycode, t_set *set, int i)
{
	if (set->map[set->p_y - 1][set->p_x] != '1')
	{
		if (!(set->c != 0 && set->map[set->p_y - 1][set->p_x] == 'E'))
		{
			if (keycode == 65362 || keycode == 'w')
			{
				ft_printf("%d\n", ++i);
				if (set->map[set->p_y - 1][set->p_x] == 'C')
					set->c--;
				if (set->map[set->p_y - 1][set->p_x] == 'E')
					set->e--;
				set->map[set->p_y][set->p_x] = '0';
				set->map[--set->p_y][set->p_x] = 'P';
				return (1);
			}
		}
	}
	return (0);
}

static int	key_right(int keycode, t_set *set, int i)
{
	if (set->map[set->p_y][set->p_x + 1] != '1')
	{
		if (!(set->c != 0 && set->map[set->p_y][set->p_x + 1] == 'E'))
		{
			if (keycode == 65363 || keycode == 'd')
			{
				ft_printf("%d\n", ++i);
				if (set->map[set->p_y][set->p_x + 1] == 'C')
					set->c--;
				if (set->map[set->p_y][set->p_x + 1] == 'E')
					set->e--;
				set->map[set->p_y][set->p_x] = '0';
				set->map[set->p_y][++set->p_x] = 'P';
				return (1);
			}
		}
	}
	return (0);
}

static int	key_down(int keycode, t_set *set, int i)
{
	if (set->map[set->p_y + 1][set->p_x] != '1')
	{
		if (!(set->c != 0 && set->map[set->p_y + 1][set->p_x] == 'E'))
		{
			if (keycode == 65364 || keycode == 's')
			{
				ft_printf("%d\n", ++i);
				if (set->map[set->p_y + 1][set->p_x] == 'C')
					set->c--;
				if (set->map[set->p_y + 1][set->p_x] == 'E')
					set->e--;
				set->map[set->p_y][set->p_x] = '0';
				set->map[++set->p_y][set->p_x] = 'P';
				return (1);
			}
		}
	}
	return (0);
}

int	key_control_hook(int keycode, t_set *set)
{
	static int	i;

	i += key_left(keycode, set, i);
	i += key_up(keycode, set, i);
	i += key_right(keycode, set, i);
	i += key_down(keycode, set, i);
	if (keycode == 65307 || set->e == 0)
		mlx_loop_end(set->mlx);
	return (0);
}
