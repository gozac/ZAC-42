/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 17:44:07 by ibakayok          #+#    #+#             */
/*   Updated: 2013/12/22 19:27:56 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "f2f.h"

int		petitbloc(char *line, int i)
{
	if (ft_isdigit((int)line[i]) == 1 || line[i] == '-')
	{
		if (ft_isdigit((int)line[i + 1]) == 0 && line[i + 1] != '-')
			return (1);
		else
			return (2);
	}
	return (0);
}

t_list	*stk_line(char *line, t_list *tmp, int y, int c)
{
	int		i;
	char	*stock;
	int		x;
	int		a;

	stock = ft_strnew(9);
	i = 0;
	x = 0;
	while (line[i] != '\0')
	{
		if ((a = petitbloc(line, i)) == 1)
		{
			stock[c] = line[i];
			stock[c + 1] = '\0';
			tmp = add_list(tmp, ft_atoi(stock), x, y);
			ft_strclr(stock);
			c = 0;
			x++;
		}
		else if (a == 2)
			stock[c++] = line[i];
		i++;
	}
	return (tmp);
}

t_list	*make_grid(int fd)
{
	char	*line;
	t_list	*tmp;
	int		y;

	y = 0;
	tmp = NULL;
	while (get_next_line(fd, &line) != 0)
	{
		tmp = stk_line(line, tmp, y, 0);
		y++;
	}
	stk_line(line, tmp, y, 0);
	return (tmp);
}
