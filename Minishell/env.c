/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 16:45:08 by ibakayok          #+#    #+#             */
/*   Updated: 2013/12/29 22:04:47 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myshell.h"

int		env(char **ft_env)
{
	int		count;

	count = 0;
	while (ft_env[count] != NULL)
	{
		ft_putstr(ft_env[count]);
		ft_putstr("\n");
		count++;
	}
	return (0);
}
