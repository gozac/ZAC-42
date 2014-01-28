/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 12:46:07 by ibakayok          #+#    #+#             */
/*   Updated: 2013/12/29 22:36:16 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "myshell.h"

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
				ft_putstr("cd : no such file or directory: ");
			else
				ft_putstr("cd : permission denied: ");
			ft_putstr(tmp);
			ft_putstr("\n");
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

	if (data == '\0')
	{
		ft_env[0][14] = ft_strjoin("pwd=", ft_env[0][3] + 5);
		return (chdir(ft_env[0][3] + 5));
	}
	else
	{
		if (data[1][0] == '-')
			return (-1);
		tmp = data[1];
		data[1] = ft_strjoin("/", data[1]);
		ft_env[0][14] = ft_strjoin(ft_env[0][14], data[1]);
		data[1] = ft_strdup(ft_env[0][14] + 4);
		ft_env[0][14] = clear_pwd(ft_env[0][14]);
		if (good(data[1], tmp) != 0)
			return (-1);
		return (chdir(data[1]));
	}
}
