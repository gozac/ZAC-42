/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 08:02:47 by ibakayok          #+#    #+#             */
/*   Updated: 2014/03/16 19:29:53 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

t_ant	*add_ant(t_ant *tmp, int i, char *str)
{
	if (tmp == NULL)
	{
		tmp = (t_ant *)malloc(sizeof(t_ant));
		tmp->num = i;
		tmp->pos = str;
	}
	else
		tmp->next = add_ant(tmp->next, i, str);
	return (tmp);
}

t_ant	*mk_ant(t_env *tmp)
{
	int		i;
	t_ant	*ant;
	t_env	*env;

	env = tmp;
	ant = NULL;
	if ((env = found_stat(env, 1)) == NULL)
	{
		ft_printf("error :pas de start\n");
		exit(0);
	}
	i = 1;
	while (i <= env->nb)
	{
		ant = add_ant(ant, i, env->name);
		i++;
	}
	return (ant);
}
