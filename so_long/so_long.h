/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:54:48 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/15 18:40:52 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif /* BUFFER_SIZE */

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libft/libft.h"

typedef struct s_set
{
	void	*col;
	void	*empty;
	void	*exit;
	void	*player;
	void	*wall;
	void	*mlx;
	void	*win;
	char	**map;
	size_t	x;
	size_t	y;
	size_t	p_x;
	size_t	p_y;
	int		c;
	int		e;
	int		p;
}	t_set;

int		key_control_hook(int keycode, t_set *set);
int		map_parse(t_set *set);
void	destroy_win(t_set *set);
void	image_align(t_set *set);
void	if_ret(int bool, t_set *set);
void	create_map(char *argv, t_set *set);

#endif