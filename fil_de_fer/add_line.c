/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 18:10:11 by ibakayok          #+#    #+#             */
/*   Updated: 2013/12/22 18:33:42 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "f2f.h"

t_list	*add_new(int z, int x, int y)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new)
	{
		new->x = (x * 20) - (y * 23);
		new->y = (y * 23) + (x * 19) - (z * 3);
		new->z = z;
		new->rx = x;
		new->ry = y;
		new->next = NULL;
	}
	return (new);
}

t_list	*add_list(t_list *list, int z, int x, int y)
{
	if (list == NULL)
	{
		list = add_new(z, x, y);
		return (list);
	}
	else
		list->next = add_list(list->next, z, x, y);
	return (list);
}
