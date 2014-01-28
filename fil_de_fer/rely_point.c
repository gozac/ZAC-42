/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rely_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 17:01:19 by ibakayok          #+#    #+#             */
/*   Updated: 2013/12/22 19:32:00 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "f2f.h"

t_dingue	small_bloc(t_dingue dingue, int x, int y, int z)
{
	dingue.x = x;
	dingue.y = y;
	dingue.z = z;
	return (dingue);
}

void	little_bloc(void *mlx, void *win, t_list *grid, t_dingue dingue)
{
	if (is_good(grid, grid->rx, grid->ry + 1) == 1)
		trace_seg4(mlx, win, dingue, dingue.z);
	if (grid->next && dingue.x >= grid->next->x)
		trace_seg4(mlx, win, dingue, grid->z);
}

void	rely_point(void *mlx, void *win, t_list *grid)
{
	t_dingue	dingue;

	if (grid)
	{
		while (grid->next)
		{
			dingue = small_bloc(dingue, grid->x, grid->y, grid->z);
			dingue.rx = grid->rx;
			dingue.ry = grid->ry;
			grid = grid->next;
			dingue.xf = grid->x;
			dingue.yf = grid->y;
			dingue.xup = findx(grid, dingue.rx, dingue.ry);
			dingue.yup = findy(grid, dingue.rx, dingue.ry);
			if (grid->x - dingue.x > grid->y - dingue.y)
				trace_seg(mlx, win, dingue, dingue.z);
			else if (is_good(grid, grid->rx + 1, grid->ry) == 1)
				trace_seg2(mlx, win, dingue, dingue.z);
			if (dingue.y >= dingue.yup && is_good(grid, grid->rx, grid->ry + 1))
				trace_seg3(mlx, win, dingue, 1);
			little_bloc(mlx, win, grid, dingue);
		}
	}
}
