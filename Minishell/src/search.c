/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 19:20:45 by ibakayok          #+#    #+#             */
/*   Updated: 2014/02/09 16:30:42 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	**ft_clean_path(char *path)
{
	char	**pathway;

	path = path + 5;
	pathway = ft_strsplit(path, ':');
	return (pathway);
}

char	*search(char *s, char *path)
{
	char			**pathway;
	int				i;

	i = 0;
	pathway = ft_clean_path(path);
	while (pathway[i] != '\0')
	{
		pathway[i] = ft_strjoin(pathway[i], "/");
		pathway[i] = ft_strjoin(pathway[i], s);
		if (access(pathway[i], X_OK) == 0)
			return (pathway[i]);
		i++;
	}
	if (access(s, X_OK) == 0)
		return (s);
	ft_printf("command not found : %s\n", s);
	return (0);
}
