/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 10:54:26 by ibakayok          #+#    #+#             */
/*   Updated: 2014/01/19 18:58:41 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		move_up(t_env *e)
{
	e->py = e->py - e->speed * sin(get_rad(e->angle));
	e->px = e->px + e->speed * cos(get_rad(e->angle));
	if (is_wall(e, e->px, e->py) == 1)
	{
		e->py = e->py + e->speed * sin(get_rad(e->angle));
		e->px = e->px - 1 * cos(get_rad(e->angle));
		if (is_wall(e, e->px, e->py) == 1)
			e->px = e->px + e->speed * cos(get_rad(e->angle));
	}
	return (0);
}

int		move_down(t_env *e)
{
	e->py = e->py + e->speed * sin(get_rad(e->angle));
	e->px = e->px - e->speed * cos(get_rad(e->angle));
	if (is_wall(e, e->px, e->py) == 1)
	{
		e->py = e->py - e->speed * sin(get_rad(e->angle));
		e->px = e->px + cos(get_rad(e->angle));
		if (is_wall(e, e->px, e->py) == 1)
			e->px = e->px - e->speed * cos(get_rad(e->angle));
	}
	return (0);
}

int		move_left(t_env *e)
{
	e->angle = e->angle - 2;
	if (e->angle <= 0)
		e->angle = e->angle + 360;
	return (0);
}

int		move_right(t_env *e)
{
	e->angle = e->angle + 2;
	if (e->angle >= 360)
		e->angle = e->angle - 360;
	return (0);
}

float	dash(float speed)
{
	if (speed == SPEED * 5)
		return (0.3);
	if (speed == SPEED)
		return (SPEED * 4);
	return (speed + 0.1);
}
