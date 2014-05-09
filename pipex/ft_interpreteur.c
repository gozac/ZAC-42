/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interpreteur.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 18:29:17 by ibakayok          #+#    #+#             */
/*   Updated: 2013/12/31 17:29:30 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/includes/libft.h"

int		ft_interpreteur(char **data, int p)
{
	t_pipex	bag;

	bag.lpipe = ft_strsplit(data[2], ' ');
	bag.rpipe = ft_strsplit(data[3], ' ');
	if ((bag.path2 = search(bag.rpipe[0], environ[p])) == 0
		|| (bag.path = search(bag.lpipe[0], environ[p])) == 0)
	{
		if ((bag.path = search(bag.lpipe[0], environ[p])) == 0)
			ft_putstr("cmd1 : command not found\n");
		if ((bag.path2 = search(bag.rpipe[0], environ[p])) == 0)
			ft_putstr("cmd2 : command not found\n");
		return (-1);
	}
	else
	{
		if ((bag.fd_input = open(data[1], O_RDONLY)) == -1)
			return (ft_putstr("open failed : file1\n"), -1);
		if (access(data[4], F_OK) == 0 && access(data[4], W_OK) != 0)
			return (ft_putstr("permission denied : file2\n"), -1);
		bag.fd_output = open(data[4], O_RDWR | O_CREAT, S_IRWXU | S_IRWXG);
		return (ft_exec(bag));
	}
}

char	*custom_path(void)
{
	char	*p;

	p = "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/X11/bin:/usr/texbin";
	return (p);
}