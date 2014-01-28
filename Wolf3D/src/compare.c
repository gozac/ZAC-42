/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 16:32:47 by ibakayok          #+#    #+#             */
/*   Updated: 2014/01/19 18:00:03 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		is_wall(t_env *e, float x, float y)
{
	x = floor(x / 64.0);
	y = floor(y / 64.0);
	return (search_map(e->map, (int)x, (int)y));
}

int		compare2(t_env *e, float rayon, float d1, float d2)
{
	int		ret;

	if (d1 < d2)
	{
		if (rayon < 180 && rayon > 0)
			e->color = 0x80D0D0;
		else
			e->color = 0x2C75FF;
		ret = d1;
	}
	else
	{
		if (rayon < 270 && rayon > 90)
			e->color = 0x318CE7;
		else
			e->color = 0x1B019B;
		ret = d2;
	}
	if (search_map(e->map, e->px / 64, e->py / 64) == 4)
		e->color = 0x9FE896;
	if (search_map(e->map, e->px / 64, e->py / 64) == 7)
		e->color = 0x1923FF;
		return (ret);
}

float	compare(t_env *e, float ay, float bx, float rayon)
{
	float ax;
	float by;
	float Xa;
	float Ya;

	if (rayon > 0 && rayon < 180)
		Ya = -64.0;
	else
		Ya = 64.0;
	ax = (e->px + (e->py - ay) / tan(rayon * M_PI / 180));
	Xa = -Ya / tan(rayon * M_PI / 180);
	if (is_wall(e, ax, ay) != 1)
	{
		while (is_wall(e, ax, ay) != 1)
		{
			ax += Xa;
			ay += Ya;
		}
	}

	if (rayon > 90 && rayon < 270)
		Xa = -64.0;
	else
		Xa = 64.0;
	by = e->py + (e->px - bx) * tan(rayon * M_PI / 180);
	Ya = -Xa * tan(rayon * M_PI / 180);
	if (is_wall(e, bx, by) != 1)
	{
		while (is_wall(e, bx, by) != 1)
		{
			bx += Xa;
			by += Ya;
		}
	}
	ax = sqrt(pow((e->px - ax), 2) + pow((e->py - ay), 2));
	bx = sqrt(pow((e->px - bx), 2) + pow((e->py - by), 2));
	return (compare2(e, rayon, ax, bx));
}
