/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 15:58:22 by ibakayok          #+#    #+#             */
/*   Updated: 2014/01/11 19:56:35 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_list	*stk_line(char *line, t_list *tmp, int y)
{
	char	**data;
	int		stock;
	int		x;

	data = ft_strsplit(line, ' ');
	x = 0;
	while (data[x] != '\0')
	{
			stock = ft_atoi(data[x]);
			tmp = add_coor(tmp, stock, x, y);
			x++;
	}
	return (tmp);
}

t_list	*raw_map(int fd)
{
	char	*line;
	t_list	*tmp;
	int		y;

	y = 0;
	tmp = NULL;
	while (get_next_line(fd, &line) != 0)
	{
		tmp = stk_line(line, tmp, y);
		y++;
	}
	tmp = stk_line(line, tmp, y);
	return (tmp);
}
