/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:54:48 by hyeson            #+#    #+#             */
/*   Updated: 2025/01/26 17:37:17 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/home/hyeson/Documents/minilibx-linux/mlx.h"
# include "/home/hyeson/Documents/minilibx-linux/mlx_int.h"
# include "../libft/libft.h"

typedef struct s_set
{
	void	*col;
	void	*empty;
	void	*exit;
	void	*player;
	void	*wall;
}	t_set;

typedef struct s_data
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

typedef struct s_point
{
	size_t	x;
	size_t	y;
}	t_point;

char	**create_map(char *argv);
void	image_align(void *mlx, t_set *set);
void	map_parse(t_set *set, char **map, t_var vars);
void	if_ret(char bool);

#endif