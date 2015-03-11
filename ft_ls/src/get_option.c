/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 18:36:26 by ibakayok          #+#    #+#             */
/*   Updated: 2015/03/02 16:51:16 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_opt	ini_opt(t_opt option)
{
	option.l = 0;
	option.r = 0;
	option.rec = 0;
	option.t = 0;
	option.a = 0;
	option.i = 1;
	option.multi = 0;
	option.words = NULL;
	return (option);
}

int		is_option(char *str)
{
	if (str == NULL)
		return (0);
	else if (str[0] == '-' && str[1] != '\0')
		return (2);
	else
		return (1);
}

t_opt	chr_option(t_opt option, char *str)
{
	if (ft_strchr(str, 'r'))
		option.r = 1;
	if (ft_strchr(str, 'l'))
		option.l = 1;
	if (ft_strchr(str, 'R'))
		option.rec = 1;
	if (ft_strchr(str, 't'))
		option.t = 1;
	if (ft_strchr(str, 'a'))
		option.a = 1;
	return (option);
}

t_wd	*add_tri(t_wd *tri, char *name, t_opt option, char *dad)
{
	struct stat	s;
	t_wd		*tmp;

	if (tri == NULL)
	{
		tri = (t_wd *)malloc(sizeof(t_wd));
		tri->str = ft_strdup(name);
		tri->dad = dad;
		lstat(dad, &tri->s);
		tri->next = NULL;
	}
	else if (option.t == 1 && lstat(dad, &s) && s.st_mtime < tri->s.st_mtime)
	{
		tmp = tri;
		tri = (t_wd *)malloc(sizeof(t_wd));
		tri->str = ft_strdup(name);
		tri->dad = dad;
		tri->s = s;
		tri->next = tmp;
	}
	else
		tri->next = add_tri(tri->next, name, option, dad);
	return (tri);
}
