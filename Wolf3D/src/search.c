/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 13:58:48 by ibakayok          #+#    #+#             */
/*   Updated: 2014/01/19 20:58:09 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		search_x(t_list *map, int objet)
{
	t_list	*tmp;

	tmp = map;
	while (tmp)
	{
		if (tmp->objet == objet)
			return (tmp->x);
		tmp = tmp->next;
	}
	return (DEPX);
}

int		search_y(t_list *map, int objet)
{
	t_list	*tmp;

	tmp = map;
	while (tmp)
	{
		if (tmp->objet == objet)
			return (tmp->y);
		tmp = tmp->next;
	}
	return (DEPY);
}

int		teleporte(t_env *e)
{
	if (search_map(e->map, e->px / 64, e->py / 64) == 4)
	{
		if (e->totmap > e->pmap)
			e->pmap += 1;
		else
			e->pmap = 1;
		e->map = raw_map(open(e->nbmap[e->pmap], O_RDONLY));
		e->px = search_x(e->map, 3) * 64 + 32;
		e->py = search_y(e->map, 3) * 64 + 32;
		wolf3d(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		mlx_string_put (e->mlx, e->win, 10, 10, 0xFF0000, "Next level");
	}
	else if (search_map(e->map, e->px / 64, e->py / 64) == 7)
	{
		ft_printf("You win the game !\n");
		exit (0);
	}
	else
		mlx_string_put (e->mlx, e->win, 10, 10,
			0xFF0000, "No teleport close to you");
	return (0);
}

int		search_map(t_list *map, int x, int y)
{
	t_list	*tmp;

	tmp = map;
	while (tmp)
	{
		if (tmp->x == x && tmp->y == y)
			return (tmp->objet);
		tmp = tmp->next;
	}
	return (1);
}

int		info(t_env *e)
{
	if (search_map(e->map, e->px / 64, e->py / 64) == 5)
		mlx_string_put (e->mlx, e->win, 10, 10,
		0xFF0000, "Tester votre Dash au traver de ce mur...");
	if (search_map(e->map, e->px / 64, e->py / 64) == 6)
	{
		mlx_string_put (e->mlx, e->win, 10, 10, 0xFF0000,
			"Alerte l'environnement va exploser ! \n");
		mlx_string_put (e->mlx, e->win, 10, 20, 0xFF0000,
			"Teleportation au milieu du cluster requise !");
	}
	if (search_map(e->map, e->px / 64, e->py / 64) == 7)
		mlx_string_put (e->mlx, e->win, 10, 10,
			0x00FF00, "Teleportation !!!!!!!");
	if (search_map(e->map, e->px / 64, e->py / 64) == 8)
	{
		mlx_string_put (e->mlx, e->win, 10, 10,
			0xFF0000, "Teleportation !!!!!!!");
		ft_printf("You lost the game");
		exit (0);
	}
	return (0);
}
