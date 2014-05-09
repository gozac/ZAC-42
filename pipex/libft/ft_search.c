/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 18:28:45 by ibakayok          #+#    #+#             */
/*   Updated: 2013/12/30 22:26:56 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "pipex.h"


char	*search(const char *s, char *path)
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
	return (0);
}
