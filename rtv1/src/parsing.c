/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 17:42:49 by ibakayok          #+#    #+#             */
/*   Updated: 2014/02/16 20:29:14 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_pln	get_plan(void)
{
	t_pln	tmp;

	tmp.x = 0;
	tmp.y = 0;
	tmp.z = -1;
	return (tmp);
}

t_cam	get_cam(int fd)
{
	t_cam	tmp;
	char	*line;

	get_next_line(fd, &line);
	tmp.xr = ft_atoi(ft_tab_spa(line));
	get_next_line(fd, &line);
	tmp.yr = ft_atoi(ft_tab_spa(line));
	get_next_line(fd, &line);
	tmp.zr = ft_atoi(ft_tab_spa(line));
	tmp.res_x = 640;
	tmp.res_y = 480;
	tmp.fov = tan((45.0 * 3.14159265358979) / 180.0);
	return (tmp);
}

t_sph	get_sph(int fd)
{
	t_sph	tmp;
	char	*line;

	get_next_line(fd, &line);
	tmp.x0 = ft_atoi(ft_tab_spa(line));
	get_next_line(fd, &line);
	tmp.y0 = ft_atoi(ft_tab_spa(line));
	get_next_line(fd, &line);
	tmp.z0 = ft_atoi(ft_tab_spa(line));
	get_next_line(fd, &line);
	tmp.r = ft_atoi(ft_tab_spa(line));
	return (tmp);
}

t_scn		get_scene(int fd)
{
	t_scn	scene;
	char	*line;
	int		i;

	i = 0;
	scene.sphere = (t_sph *)malloc(sizeof(t_sph) * 3);
	scene.plan = (t_pln *)malloc(sizeof(t_pln) * 1);
	while (get_next_line(fd, &line) != 0)
	{
		if (line[0] != '#')
		{
			if (ft_strcmp(ft_tab_spa(line), "camera") == 0)
				scene.cam = get_cam(fd);
			else if (ft_strcmp(ft_tab_spa(line), "sphere") == 0)
			{
				scene.sphere[i] = get_sph(fd);
				i++;
			}
		}
	}
	scene.plan[0] = get_plan();
	return (scene);
}
