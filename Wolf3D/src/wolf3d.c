/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 16:32:19 by ibakayok          #+#    #+#             */
/*   Updated: 2014/01/19 20:58:43 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		wolfdraw(t_env *e, int hauteur, int i, int color)
{
	int		c;
	int		down;
	int		up;

	down = DOWN;
	up = UP;
	if (color == 0x9FE896 || color == 0x1923FF)
	{
		down = 0x2966E8;
		up = 0xE842AB;
	}
	if (color == 0x1923FF)
		down = 0x2821FF;
	c = WINY;
	while (c > 0)
	{
		if (c > ((hauteur / 2) + WINY / 2))
			mlx_pixel_img(e, i, -(c - WINY), up);
		if (c > WINY / 2 - (hauteur / 2) && c < (hauteur / 2) + WINY / 2)
			mlx_pixel_img(e, i, -(c - WINY), color);
		if (c < WINY / 2 - (hauteur / 2))
			mlx_pixel_img(e, i, -(c - WINY), down);
		c--;
	}
	return (0);
}

float	rayonhz(t_env *e, float rayon)
{
	float	ay;

	if (rayon > 0 && rayon < 180)
		ay = floor(e->py / 64.0) * (64.0) - 0.01;
	else
		ay = floor(e->py / 64.0) * (64.0) + 64.0;
	return (ay);
}

float	rayonvt(t_env *e, float rayon)
{
	float	bx;


	if (rayon > 90 && rayon < 270)
	bx = floor(e->px / 64.0) * (64.0) - 0.01;
	else
		bx = floor(e->px / 64.0) * (64.0) + 64.0;
	return (bx);
}

float	walldist(t_env *e, float rayon)
{
	float	bx;
	float	ay;
	float	dist;

	ay = rayonhz(e, rayon);
	bx = rayonvt(e, rayon);
	dist = compare(e, ay , bx, rayon);
	return (dist * cos(get_rad(rayon - e->angle)) * 0.050);
}

int		wolf3d(t_env *e)
{
	float	hauteur;
	float	rayon;
	float	scalex;
	int		i;

	i = 0;
	rayon = e->angle + FOV / 2;
	scalex = FOV / WINX;
	while (i < WINX)
	{
		hauteur = (64 / walldist(e, rayon) * 22);
		wolfdraw(e, (int)hauteur, i, e->color);
		rayon = rayon - scalex;
		if (rayon < 0)
			rayon = rayon + 360;
		if (rayon > 360)
			rayon = rayon - 360;
		i++;
	}
	return (0);
}
