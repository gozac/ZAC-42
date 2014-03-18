/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_seg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 19:04:58 by ibakayok          #+#    #+#             */
/*   Updated: 2014/02/16 19:44:23 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "f2f.h"

void	trace_seg(void *mlx, void *win, t_dingue dingue, int z)
{
	int		x;
	int		y;
	int		i;

	x = dingue.x;
	i = 0;
	if (z > 0)
		i = 1;
	if (z < 0)
		i = -1;
	while (x <= dingue.xf)
	{
		y = (dingue.y + ((dingue.yf - dingue.y) * (x - dingue.x))
		/ (dingue.xf - dingue.x));
		mlx_pixel_put(mlx, win, (x + 942), (y + 150), 0xFFFFFF - i);
		x++;
		i = i * 10;
	}
}

void	trace_seg2(void *mlx, void *win, t_dingue dingue, int z)
{
	int		x;
	int		y;
	int		i;

	x = dingue.y;
	i = 0;
	if (z > 0)
		i = 2;
	if (z < 0)
		i = -1;
	while (x <= dingue.yf)
	{
		y = (dingue.x + ((dingue.xf - dingue.x) * (x - dingue.y))
		/ (dingue.yf - dingue.y));
		mlx_pixel_put(mlx, win, (y + 942), (x + 150), 0xFFFFFF - i);
		x++;
		i = i * 10;
	}
}

void	trace_seg4(void *mlx, void *win, t_dingue dingue, int z)
{
	int		x;
	int		y;
	int		i;

	x = dingue.y;
	i = 0;
	if (z > 0)
		i = 2;
	if (z < 0)
		i = -1;
	while (x <= dingue.yup)
	{
		y = (dingue.x + ((dingue.xup - dingue.x) * (x - dingue.y))
		/ (dingue.yup - dingue.y));
		mlx_pixel_put(mlx, win, (y + 942), (x + 150), 0xFFFFFF - i);
		x++;
		i = i * 10;
	}
}



void	trace_seg3(void *mlx, void *win, t_dingue dingue, int z)
{
	int		x;
	int		y;
	int		i;

	x = dingue.xup;
	i = 0;
	if (z > 0)
		i = 1;
	if (z < 0)
		i = -1;
	while (x <= dingue.x)
	{
		y = (dingue.yup + ((dingue.y - dingue.yup) * (x - dingue.xup))
		/ (dingue.x - dingue.xup));
		mlx_pixel_put(mlx, win, (x + 942), (y + 150), 0xFFFFFF - i);
		x++;
		i = i * 10;
	}
}
