/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_coor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 18:35:10 by ibakayok          #+#    #+#             */
/*   Updated: 2014/01/11 15:53:54 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "wolf3d.h"

t_list	*add_new(int objet, int x, int y)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new)
	{
		new->objet = objet;
		new->x = x;
		new->y = y;
		new->next = NULL;
	}
	return (new);
}

t_list	*add_coor(t_list *list, int objet, int x, int y)
{
	if (list == NULL)
	{
		list = add_new(objet, x, y);
		return (list);
	}
	else
		list->next = add_coor(list->next, objet, x, y);
	return (list);
}
