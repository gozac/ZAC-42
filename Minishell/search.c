/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 17:01:30 by ibakayok          #+#    #+#             */
/*   Updated: 2013/12/29 18:06:15 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "myshell.h"


char	*search(const char *s, char *path)
{
	char			**pathway;
	DIR				*fichier;
	struct dirent	*lecture;
	int				i;

	i = 0;
	pathway = ft_clean_path(path);
	while (pathway[i] != '\0')
	{
		fichier = opendir(pathway[i]);
		while ((lecture = readdir(fichier)))
		{
			if (ft_strcmp(lecture->d_name, s) == 0)
				return (pathway[i]);
		}
		closedir(fichier);
		i++;
	}
	return (0);
}
