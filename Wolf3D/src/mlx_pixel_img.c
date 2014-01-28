/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 15:36:29 by ibakayok          #+#    #+#             */
/*   Updated: 2014/01/19 20:52:24 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "wolf3d.h"

int		mlx_pixel_img(t_env *e, int x, int y, int color)
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
