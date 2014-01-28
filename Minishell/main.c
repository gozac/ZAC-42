/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 18:32:28 by ibakayok          #+#    #+#             */
/*   Updated: 2013/12/29 22:08:33 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myshell.h"

int		main(void)
{
	char	*line;
	char	**data;
	char	**ft_env;
	int		i;

	i = 0;
	while (environ[i] != '\0')
		i++;
	ft_env = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (environ[++i] != '\0')
		ft_env[i] = ft_strdup(environ[i]);
	ft_env[i] = '\0';
	ft_putstr("$> ");
	while (get_next_line(0, &line))
	{
		if (*line)
		{
			data = ft_strsplit(line, ' ');
			if (built_in(data, &ft_env) == 1)
				ft_interpreteur(data);
		}
		ft_putstr("$> ");
	}
	return (-1);
}
