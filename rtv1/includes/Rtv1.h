/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 19:23:21 by ibakayok          #+#    #+#             */
/*   Updated: 2014/02/16 22:34:30 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct	s_cam
{
	int		xr;
	int		yr;
	int		zr;
	int		rot_x;
	int		rot_y;
	int		rot_z;
	int		f;
	int		res_x;
	int		res_y;
	float	fov;
	int		pitch_x;
	int		pitch_y;
}				t_cam;

typedef struct	s_mat
{
	int		c1;
	int		c2;
	int		c3;
	int		c4;
	int		*coeff;
}				t_mat;

typedef struct	s_vec
{
	int		vx;
	int		vy;
	int		vz;
}				t_vec;

typedef struct	s_inter
{
	int		x;
	int		y;
	int		z;
}				t_inter;

typedef struct	s_sph
{
	int		x0;
	int		y0;
	int		z0;
	int		r;
	t_mat	clr;
}				t_sph;

typedef struct	s_pln
{
	int		x;
	int		y;
	int		z;
	int		d;
	t_mat	clr;
}				t_pln;

typedef struct	s_scn
{
	t_pln	*plan;
	t_sph	*sphere;
	t_cam	cam;
}				t_scn;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		sizeline;
	int		endian;
	int		bpp;
	t_scn	scene;
}				t_mlx;
t_scn		get_scene(int fd);

#endif
