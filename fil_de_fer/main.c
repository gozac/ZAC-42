/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 17:48:03 by ibakayok          #+#    #+#             */
/*   Updated: 2013/12/22 20:33:42 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include "f2f.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_list	*grid;
	void	*mlx;
	void	*win;

	if (argc < 2)
	{
		ft_putstr("usage : ./fdf file1\n");
		return (-1);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		perror(argv[1]);
		return (-1);
	}
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1020, "42");
	grid = make_grid(fd);
	rely_point(mlx, win, grid);
	mlx_loop(mlx);
	return (0);
}
