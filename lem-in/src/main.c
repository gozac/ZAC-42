/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 16:57:04 by ibakayok          #+#    #+#             */
/*   Updated: 2014/03/20 18:43:52 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		main(void)
{
	t_env	*anthill;
	t_ant	*ant;
	char	*line;
	t_env	*way;

	get_next_line(0, &line);
	if ((anthill = mk_env(NULL, 0, line)) == NULL)
		return (ft_printf("(empty map)\n"), -1);
//	if ((way = mk_way(anthill)) == NULL)
//		return (ft_printf("c la merde !\n"), -1);
	way = mk_way(anthill);
	/*while (anthill)
	{
		ft_printf("name = %s\n", anthill->name);
		while (anthill->tup)
		{
			ft_printf("tup = %s\n", anthill->tup->name);
			anthill->tup = anthill->tup->next;
		}
		anthill = anthill->next;
	}*/
	ant = mk_ant(anthill);
	while (mk_move(way, &ant) != 0)
		ft_printf("\n");
	return (0);
}
