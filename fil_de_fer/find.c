/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 17:42:53 by ibakayok          #+#    #+#             */
/*   Updated: 2013/12/22 20:30:10 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f2f.h"

int		findy(t_list *list, int rx, int ry)
{
	while (list)
	{
		if (list->rx == rx && list->ry == ry + 1)
			return (list->y);
		list = list->next;
	}
	return (42);
}

int		findx(t_list *list, int rx, int ry)
{
	while (list)
	{
		if (list->rx == rx && list->ry == ry + 1)
			return (list->x);
		list = list->next;
	}
	return (42);
}
