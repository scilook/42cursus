/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:02:56 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/15 18:53:02 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_left(int keycode, t_set *set)
{
	if (set->map[set->p_y][set->p_x - 1] != '1')
	{
		if (!(set->c != 0 && set->map[set->p_y][set->p_x - 1] == 'E'))
		{
			if (keycode == 65361 || keycode == 'a')
			{
				if (set->map[set->p_y][set->p_x - 1] == 'C')
					set->c--;
				if (set->map[set->p_y][set->p_x - 1] == 'E')
					set->e--;
				set->map[set->p_y][set->p_x] = '0';
				set->map[set->p_y][--set->p_x] = 'P';
			}
		}
	}
}

void	key_up(int keycode, t_set *set)
{
	if (set->map[set->p_y - 1][set->p_x] != '1')
	{
		if (!(set->c != 0 && set->map[set->p_y - 1][set->p_x] == 'E'))
		{
			if (keycode == 65362 || keycode == 'w')
			{
				if (set->map[set->p_y - 1][set->p_x] == 'C')
					set->c--;
				if (set->map[set->p_y - 1][set->p_x] == 'E')
					set->e--;
				set->map[set->p_y][set->p_x] = '0';
				set->map[--set->p_y][set->p_x] = 'P';
			}
		}
	}
}

void	key_right(int keycode, t_set *set)
{
	if (set->map[set->p_y][set->p_x + 1] != '1')
	{
		if (!(set->c != 0 && set->map[set->p_y][set->p_x + 1] == 'E'))
		{
			if (keycode == 65363 || keycode == 'd')
			{
				if (set->map[set->p_y][set->p_x + 1] == 'C')
					set->c--;
				if (set->map[set->p_y][set->p_x + 1] == 'E')
					set->e--;
				set->map[set->p_y][set->p_x] = '0';
				set->map[set->p_y][++set->p_x] = 'P';
			}
		}
	}
}

void	key_down(int keycode, t_set *set)
{
	if (set->map[set->p_y + 1][set->p_x] != '1')
	{
		if (!(set->c != 0 && set->map[set->p_y + 1][set->p_x] == 'E'))
		{
			if (keycode == 65364 || keycode == 's')
			{
				if (set->map[set->p_y + 1][set->p_x] == 'C')
					set->c--;
				if (set->map[set->p_y + 1][set->p_x] == 'E')
					set->e--;
				set->map[set->p_y][set->p_x] = '0';
				set->map[++set->p_y][set->p_x] = 'P';
			}
		}
	}
}

int	key_control_hook(int keycode, t_set *set)
{
	if (keycode == 65307)
		destroy_win(set);
	key_left(keycode, set);
	key_up(keycode, set);
	key_right(keycode, set);
	key_down(keycode, set);
	if (set->e == 0)
		destroy_win(set);
	return (0);
}


