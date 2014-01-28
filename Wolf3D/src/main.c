/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 15:57:51 by ibakayok          #+#    #+#             */
/*   Updated: 2014/01/19 19:08:09 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		expose_hook(t_env *e)
{
	wolf3d(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_string_put (e->mlx, e->win, 10, 10, 0xFF0000, "Bienvenue Agent X11");
	mlx_string_put (e->mlx, e->win, 10, 20, 0xFF0000, "Votre mission est de");
	mlx_string_put (e->mlx, e->win, 10, 30, 0xFF0000, "vous echapez !");
	mlx_string_put (e->mlx, e->win, 10, 40, 0xFF0000, "Sans segfault");
	return (0);
}

int		key_press(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 116)
		teleporte(e);
	if (keycode == 32)
		e->speed = dash(e->speed);
	if (keycode == 65506)
		e->speed = SPEED * 2;
	if (keycode == 65508)
		e->speed = SPEED / 2;
	if (keycode == 65361 || keycode == 97)
		e->save[0] = 1;
	if (keycode == 65362 || keycode == 119)
		e->save[1] = 1;
	if (keycode == 65363 || keycode == 100)
		e->save[2] = 1;
	if (keycode == 65364 || keycode == 115)
		e->save[3] = 1;
	return (0);
}

int		key_release(int keycode, t_env *e)
{
	if (keycode == 32 || keycode == 65506 || keycode == 65508)
		e->speed = SPEED;
	if (keycode == 65361 || keycode == 97)
		e->save[0] = 0;
	if (keycode == 65362 || keycode == 119)
		e->save[1] = 0;
	if (keycode == 65363 || keycode == 100)
		e->save[2] = 0;
	if (keycode == 65364 || keycode == 115)
		e->save[3] = 0;
	return (0);
}

int		loop_hook(t_env *e)
{
	int		i;
	int		ok;

	i = -1;
	ok = 0;
	while (++i != 4)
	{
		if (e->save[i] == 1)
			ok = 1;
	}
	if (ok == 0)
		return (0);
	if (e->save[0] == 1)
		move_right(e);
	if (e->save[1] == 1)
		move_up(e);
	if (e->save[2] == 1)
		move_left(e);
	if (e->save[3] == 1)
		move_down(e);
	wolf3d(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	info(e);
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_env	e;

	fd = open(argv[1], O_RDONLY);
	if (argc == 1)
		return (ft_printf("wolf3d : Pas de niveau\n"), -1);
	e.nbmap = argv;
	e.totmap = argc - 1;
	e.map = raw_map(fd);
	e.pmap = 1;
	e.speed = SPEED;
	e.px = search_x(e.map, 3) * 64 + 32;
	e.py = search_y(e.map, 3) * 64 + 32;
	e.angle = ANGLE;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WINX, WINY, "Wolf3d");
	e.img = mlx_new_image(e.mlx, WINX, WINY);
	e.data = mlx_get_data_addr(e.img, &e.bpp, &e.sizeline, &e.endian);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_hook(e.win, 2, 1, key_press, &e);
	mlx_hook(e.win, 3, 2, key_release, &e);
	mlx_loop_hook(e.mlx, loop_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
