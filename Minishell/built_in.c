/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 12:20:51 by ibakayok          #+#    #+#             */
/*   Updated: 2013/12/29 22:50:32 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myshell.h"

int		built_in(char **data, char ***ft_env)
{
	if (ft_strcmp("quit", data[0]) == 0 || ft_strcmp("exit", data[0]) == 0)
	{
		if (data[1])
			exit(ft_atoi(data[1]));
		exit(0);
	}
	if (ft_strcmp("env", data[0]) == 0)
		return (env(*ft_env));
	if (ft_strcmp("cd", data[0]) == 0)
	{
		if (data[1] == '\0')
			return (cd(NULL, ft_env));
		else
			return (cd(data, ft_env));
	}
	if (ft_strcmp("setenv", data[0]) == 0)
	{
		if (data[1] && data[2] && data[3])
			return (ft_setenv(data[1], data[2], ft_atoi(data[3]), ft_env));
		ft_putstr("setenv: name, value, overwrite\n");
		return (-1);
	}
	if (ft_strcmp("unsetenv", data[0]) == 0)
		return (ft_unsetenv(data[1], ft_env));
	return (1);
}
