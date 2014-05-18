/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interpreteur.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 18:54:31 by ibakayok          #+#    #+#             */
/*   Updated: 2014/04/27 21:45:04 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		built_in(char **data, char ***ft_env)
{
	if (ft_strcmp("quit", data[0]) == 0 || ft_strcmp("exit", data[0]) == 0)
	{
		if (data[1] != NULL)
			exit(ft_atoi(data[1]));
		exit(0);
	}
	if (ft_strcmp("env", data[0]) == 0)
		return (env(*ft_env));
	if (ft_strcmp("cd", data[0]) == 0)
	{
		if (data[1] == NULL)
			return (cd(NULL, ft_env));
		return (cd(data, ft_env));
	}
	return (1);
}

int		ft_interpreteur(char **data, char **ft_env)
{
	char	*path;

	if ((path = search(data[0], ft_findpath(ft_env))) == 0)
		return (-1);
	else
	{
		ft_exec(path, data, ft_env);
		return (0);
	}
}
