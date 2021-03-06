/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 15:52:28 by ibakayok          #+#    #+#             */
/*   Updated: 2016/03/06 17:33:29 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	prt_dir(t_opt option, t_wd *tri)
{
	if (tri->str[0] != '.' || option.a == 1)
	{
		if (option.l == 1)
			stat_dir(tri);
		if (option.rec == 1 && S_ISDIR(tri->s.st_mode)
			&& ft_strcmp("..", tri->str) && ft_strcmp(".", tri->str))
		{
			ft_printf("%s:\n{\n", tri->str);
			option.i++;
			list_dir(option, tri->dad);
			ft_printf("}\n");
		}
		else
			ft_printf("%s\n", tri->str);
	}
}

void	ordre_dir(t_opt option, t_wd *tri)
{
	if (option.r == 0)
	{
		while (tri)
		{
			prt_dir(option, tri);
			tri = tri->next;
		}
	}
	else if (tri)
	{
		ordre_dir(option, tri->next);
		prt_dir(option, tri);
	}
}

int		testsolo(t_wd **tri, t_opt option, DIR *fichier, char *str)
{
	if (option.i > REC)
		return (-1);
	if (!fichier)
	{
		if (errno != ENOTDIR)
		{
			ft_printf("ls: ");
			perror(str);
			return (-1);
		}
		*tri = add_tri(*tri, str, option, str);
		return (1);
	}
	return (0);
}

int		list_dir(t_opt option, char *str)
{
	DIR				*fichier;
	struct dirent	*lecture;
	t_wd			*tritri;
	int				i;
	int				test;

	i = 0;
	tritri = NULL;
	test = 0;
	fichier = opendir(str);
	if ((test = testsolo(&tritri, option, fichier, str)) == -1)
		return (0);
	while (fichier && (lecture = readdir(fichier)))
	{
		tritri = add_tri(tritri, lecture->d_name, option
			, ft_strjoin(ft_strjoin(str, "/"), lecture->d_name));
		i++;
	}
	tritri = tri_list(tritri, i);
	if (test == 0)
		closedir(fichier);
	ordre_dir(option, tritri);
	return (1);
}
