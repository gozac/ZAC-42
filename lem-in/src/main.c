/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 16:57:04 by ibakayok          #+#    #+#             */
/*   Updated: 2014/03/18 20:17:06 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		main(void)
{
	t_env	*anthill;
	t_ant	*ant;
	char	*line;
//	t_env	*way;

	get_next_line(0, &line);
	if ((anthill = mk_env(NULL, 0, line)) == NULL)
		return (ft_printf("(empty map)\n"), -1);
	//while (anthill)
	//{
	//	ft_printf("name = %s", anthill->name);
	//	anthill = anthill->next;
	//}
	//if ((way = mk_way(anthill)) == NULL)
	//	return (-1);
	ant = mk_ant(anthill);
	while (mk_move(/*way*/anthill, &ant) != 0)
		ft_printf("\n");
	return (0);
}
