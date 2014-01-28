/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 17:34:47 by ibakayok          #+#    #+#             */
/*   Updated: 2013/12/29 23:10:56 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myshell.h"

int		ft_sc(char *s, int c)
{
	char	ret;
	int		i;

	i = 0;
	ret = (char)c;
	while (s[i] != '\0' && s[i] != ret)
		i++;
	return (i);
}

int		ft_unsetenv(char *name, char ***ft_env)
{
	int		i;
	char	**bis;

	i = 0;
	bis = *ft_env;
	while (bis[i] != '\0')
	{
		if (ft_strcmp(ft_strndup(bis[i], ft_sc(bis[i], '=')), name) == 0)
		{
			bis[i] = "(null)";
			return (0);
		}
		i++;
	}
	ft_putstr("unsetenv : not in environ : ");
	ft_putstr(name);
	ft_putstr("\n");
	return (-1);
}
