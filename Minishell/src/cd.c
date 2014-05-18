/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 12:46:07 by ibakayok          #+#    #+#             */
/*   Updated: 2014/04/27 21:29:42 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "shell.h"

char	*ft_chrrdup(char *s, int c)
{
	char	ret;
	int		i;
	int		b;

	b = -1;
	ret = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ret)
			b = i;
		i++;
	}
	s = ft_strndup(s, b);
	return (s);
}

char	*clear_pwd(char *pwd)
{
	if (ft_strcmp(ft_strrchr(pwd, '/'), "/..") == 0)
		pwd = ft_chrrdup(ft_chrrdup(pwd, '/'), '/');
	else if (ft_strcmp(ft_strrchr(pwd, '/'), "/.") == 0)
		pwd = ft_chrrdup(pwd, '/');
	return (pwd);
}

int		good(char *path, char *tmp)
{
	struct stat		sts;

	if (access(path, F_OK) != 0 || access(path, R_OK) != 0)
	{
		if (access(path, F_OK) != 0)
			ft_printf("cd : no such file or directory: %s\n", tmp);
		else
			ft_printf("cd : permission denied: %s\n", tmp);
		return (-1);
	}
	stat(path, &sts);
	if ((sts.st_mode & S_IFMT) != S_IFDIR)
	{
		ft_putstr("cd : not a directory: ");
		ft_putstr(tmp);
		ft_putstr("\n");
		return (-1);
	}
	return (0);
}

int		cd(char **data, char ***ft_env)
{
	char	*tmp;
	char	*tmp2;

	if (data)
	{
		tmp2 = ft_strdup(ft_env[0][14]);
		tmp = data[1];
		tmp = ft_strjoin("/", tmp);
		ft_env[0][14] = ft_strjoin(ft_env[0][14], tmp);
		tmp = ft_strdup(ft_env[0][14] + 4);
		ft_env[0][14] = clear_pwd(ft_env[0][14]);
		if (good(tmp, data[1]) != 0)
		{
			ft_env[0][14] = tmp2;
			return (-1);
		}
		return (chdir(tmp));
	}
	ft_env[0][14] = ft_strjoin("PWD=", ft_env[0][3] + 5);
	return (chdir(ft_env[0][3] + 5));
}
