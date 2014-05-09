/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 18:33:07 by ibakayok          #+#    #+#             */
/*   Updated: 2014/04/28 04:00:01 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include "get_next_line.h"
# include "../libft/includes/libft.h"
# define ANGLE 90.0000
# define DEPX 1.0
# define DEPY 1.0
# define WINX 640.0
# define WINY (WINX / 1.6)
# define FOV 60.0
# define SPEED 1.0
# define UP 0x2BFAFA
# define DOWN 0x2D241E


typedef struct s_list	t_list;

struct		s_list
{
	int		x;
	int		y;
	int		objet;
	t_list	*next;
};

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		bpp;
	int		color;
	int		totmap;
	char	**nbmap;
	int		pmap;
	int		sizeline;
	int		endian;
	t_list	*map;
	float	speed;
	float		px;
	float		py;
	int		angle;
	int		save[4];
}			t_env;

t_list	*add_coor(t_list *list, int objet, int x, int y);
int		ft_printf(const char *format, ...);
t_list	*raw_map(int fd);
int		search_map(t_list *map, int x, int y);
float	compare(t_env *e, float ay, float bx, float rayon);
int		wolf3d(t_env *e);
int		mlx_pixel_img(t_env *e, int x, int y, int color);
float	get_rad(float alpha);
int		is_wall(t_env *e, float x, float y);
int		move_up(t_env *e);
int		move_down(t_env *e);
int		move_left(t_env *e);
int		move_right(t_env *e);
float	dash(float speed);
int		search_y(t_list *map, int objet);
int		teleporte(t_env *e);
int		search_x(t_list *map, int objet);
int		info(t_env *e);

#endif
