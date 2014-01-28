/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interpreteur.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 18:33:11 by ibakayok          #+#    #+#             */
/*   Updated: 2013/12/29 18:52:48 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myshell.h"

int		ft_interpreteur(char **data)
{
	char	*path;

	if ((path = search(data[0], environ[0])) == 0)
	{
		ft_putstr("command not found\n");
		return (-1);
	}
	else
	{
		path = ft_strjoin(path, "/");
		path = ft_strjoin(path, data[0]);
		ft_exec(path, data);
		return (0);
	}
}
