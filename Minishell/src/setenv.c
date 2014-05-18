/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 17:34:40 by ibakayok          #+#    #+#             */
/*   Updated: 2014/04/27 21:31:23 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_csrealloc(char ***garot, char *s)
{
	char	**tmp;
	char	**ft_env;
	int		i;

	i = 0;
	ft_env = *garot;
	while (ft_env[i] != '\0')
		i++;
	tmp = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (ft_env[++i] != '\0')
		tmp[i] = ft_strdup(ft_env[i]);
	tmp[i] = '\0';
	ft_env = (char **)malloc(sizeof(char *) * (i + 2));
	i = -1;
	while (tmp[++i] != '\0')
		ft_env[i] = ft_strdup(tmp[i]);
	ft_env[i] = ft_strdup(s);
	ft_env[i + 1] = '\0';
	*garot = ft_env;
	return (0);
}

int		ft_s(char *s, int c)
{
	char	ret;
	int		i;

	i = 0;
	if (s)
	{
		ret = (char)c;
		while (s[i] != '\0' && s[i] != ret)
			i++;
	}
	return (i);
}

int		ft_setenv(char *name, char *value, int overwrite, char ***ft_env)
{
	int		i;
	char	**bis;
	int		n;

	i = 0;
	n = 0;
	while ((*ft_env)[i] != '\0')
		i++;
	bis = (char **)malloc(sizeof(char *) * (i + 1));
	bis[i + 1] = NULL;
	i = 0;
	while ((*ft_env)[n] != '\0')
	{
		if (!ft_strcmp(ft_strndup((*ft_env)[n], ft_s((*ft_env)[n], '=')), name)
			&& overwrite == 0)
			bis[i++] = ft_strjoin(ft_strjoin(name, "="), value);
		else
			bis[i++] = (*ft_env)[n];
		n++;
	}
	if (i == n)
		bis[i] = ft_strjoin(ft_strjoin(name, "="), value);
	*ft_env = bis;
	return (0);
}
