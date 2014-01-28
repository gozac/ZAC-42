/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_good.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 16:21:40 by ibakayok          #+#    #+#             */
/*   Updated: 2013/12/22 20:29:54 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f2f.h"

int		is_good(t_list *list, int x, int y)
{
	while (list)
	{
		if (list->rx == x && list->ry == y)
			return (1);
		list = list->next;
	}
	return (0);
}
