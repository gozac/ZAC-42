/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 16:45:08 by ibakayok          #+#    #+#             */
/*   Updated: 2014/04/27 21:01:45 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		env(char **ft_env)
{
	int		count;

	count = 0;
	while (ft_env[count] != NULL)
	{
		if (ft_env[count])
			ft_printf("%s\n", ft_env[count]);
		count++;
	}
	return (0);
}
