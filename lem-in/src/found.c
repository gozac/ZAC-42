/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 16:49:20 by ibakayok          #+#    #+#             */
/*   Updated: 2014/03/16 19:25:43 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

t_env	*found_stat(t_env *env, int p)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (tmp->stat == p)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_env	*found_name(t_env *env, char *str)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, str) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int		found_max(t_env *env)
{
	t_env	*tmp;
	int		i;

	tmp = env;
	i = 1;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
