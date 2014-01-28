/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 17:34:40 by ibakayok          #+#    #+#             */
/*   Updated: 2013/12/29 23:10:45 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myshell.h"


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

int		ft_cs(char *s, int c)
{
	char	ret;
	int		i;

	i = 0;
	ret = (char)c;
	while (s[i] != '\0' && s[i] != ret)
		i++;
	return (i);
}

int		ft_setenv(char *name, char *value, int overwrite, char ***ft_env)
{
	int		i;
	char	**bis;

	bis = *ft_env;
	i = 0;
	while (bis[i] != '\0')
	{
		if (ft_strcmp(ft_strndup(bis[i], ft_cs(bis[i], '=')), name) == 0)
		{
			if (overwrite == 0)
			{
				name = ft_strjoin(name, "=");
				bis[i] = ft_strjoin(name, value);
				*ft_env = bis;
			}
			return (0);
		}
		i++;
	}
	name = ft_strjoin(name, "=");
	i = ft_csrealloc(ft_env, ft_strjoin(name, value));
	return (0);
}
