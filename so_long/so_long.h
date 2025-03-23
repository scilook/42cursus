/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:54:48 by hyeson            #+#    #+#             */
/*   Updated: 2025/03/23 17:12:17 by hyeson           ###   ########.fr       */
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

typedef struct s_point
{
	size_t	x;
	size_t	y;
}	t_point;

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

typedef struct s_queue
{
	t_list	*front;
	t_list	*rear;
	int		size;
}	t_queue;

int		key_control_hook(int keycode, t_set *set);
int		ft_pointcmp(t_point *content, t_list *lst);
int		map_parse(t_set *set);
void	lst_clear(t_list *lst);
void	destroy_win(t_set *set);
void	image_align(t_set *set);
void	condition_check(t_set *set);
void	if_ret(int bool, t_set *set);
void	create_map(char *argv, t_set *set);
void	free_queue(t_queue *queue);
void	enqueue_point(t_queue *queue, int x, int y);
t_point	*dequeue_point(t_queue *queue);
t_queue	*init_queue(void);
t_list	*point_list(t_point *point);

#endif