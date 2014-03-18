/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_to_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 04:30:15 by ibakayok          #+#    #+#             */
/*   Updated: 2014/03/18 20:14:18 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		isfm(t_ant *ant, char *str)
{
	t_ant	*tmp;

	tmp = ant;
	while (tmp)
	{
		if (ft_strcmp(tmp->pos, str) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_env	*found_way(t_env *env, t_env *src, int	i)
{
	t_env	*tmp;
	t_tup	*tmp2;

	tmp = NULL;
	if (src == NULL)
		return (ft_printf("ca a foirer %d\n", i), src);
	tmp2 = src->tup;
	ft_printf("[%d] = [%s]\n", i, src->name);
	src->next = NULL;
	if (src->stat == 2)
		return (src);
	if (i == 0)
		return (NULL);
	while (tmp2)
	{
		if ((tmp = found_way(env, found_name(env, tmp2->name), i - 1)) != NULL)
		{
			ft_printf("ca a pas foirer %d\n", i);
			src->next = tmp;
		}
		tmp2 = tmp2->next;
	}
	return (src);
}

t_env	*mk_way(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	if (found_stat(env, 2) == NULL || (tmp = found_stat(env, 1)) == NULL)
		return (write(2, "Error : Missing start or end\n", 29), NULL);
	tmp = found_way(env, tmp, found_max(env));
	if (tmp->next == NULL)
		return (write(2, "Error : No way\n", 15), NULL);
	ft_printf("tmp = %s, tmp->next = %s\n", tmp->name, tmp->next->name);
	return (tmp);
}

int		mk_move(t_env *way, t_ant **fm)
{
	t_ant	*tmp;
	t_env	*tmp2;
	int		p;

	p = 0;
	tmp = (*fm);
	while (tmp)
	{
		tmp2 = found_name(way, tmp->pos);
		if (tmp2->next != NULL && (*fm) != NULL && isfm((*fm), tmp2->next->name) != 1)
		{
			p = 1;
			tmp->pos = tmp2->next->name;
			ft_printf("L%d-%s", tmp->num, tmp->pos);
		}
		tmp = tmp->next;
	}
	return (p);
}
