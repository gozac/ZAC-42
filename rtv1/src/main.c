/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 17:28:47 by ibakayok          #+#    #+#             */
/*   Updated: 2014/02/16 22:30:19 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		mlx_pixel_img(t_mlx *e, int x, int y, int color)
{
	int				i;
	unsigned int	color2;

	color2 = mlx_get_color_value(e->mlx, color);
	i = (y * e->sizeline) + (x * (e->bpp / 8));
	e->data[i] = (color2 & 0xFF);
	i++;
	if (e->bpp >= 16)
		e->data[i] = ((color2 & 0xFF00) >> 8);
	i++;
	if (e->bpp >= 32)
		e->data[i] = ((color2 & 0xFF0000) >> 16);
	return (0);
}

float		psc(float *a, float *b)
{
	return ((a[0] * b[0]) + (a[1] * b[1]) + (a[2] * b[2]));
}

void	draw(int x, int y, t_scn i, t_mlx *e)
{
	float	var[3];
	float	point[3];
	float	di[3];
	int		d;

	d = 0xFF0000;
	point[0] = (2 * ((x + 0.5) / 640) - 1) * 640 / 480 * i.cam.fov;
	point[1] = (1 - 2 * ((y + 0.5) / 480)) * i.cam.fov;
	point[2] = i.plan[0].z;
	var[0] = (float)i.cam.xr - i.sphere[0].x0;
	var[1] = (float)i.cam.yr - i.sphere[0].y0;
	var[2] = (float)i.cam.zr - i.sphere[0].z0;
	di[0] = psc(point, point);
	di[1] = 2 * psc(point, var);
	di[2] = psc(var, var) - i.sphere[0].r;
	if (((di[1] * di[1]) - (4 * di[0] * di[2])) >= 0)
		mlx_pixel_img(e, x, y, d - x);
	else
		mlx_pixel_img(e, x, y, 0x000000);
}

int		expose_hook(t_mlx *e)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < e->scene.cam.res_x)
	{
		y = 0;
		while (y < e->scene.cam.res_y)
		{
			draw(x, y, e->scene, e);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		main(void)
{
	t_mlx	e;
	t_scn	scene;

	scene = get_scene(0);
	e.scene = scene;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, scene.cam.res_x, scene.cam.res_y, "Rtv1");
	e.img = mlx_new_image(e.mlx, scene.cam.res_x, scene.cam.res_y);
	e.data = mlx_get_data_addr(e.img, &e.bpp, &e.sizeline, &e.endian);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
