/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 13:08:47 by ibakayok          #+#    #+#             */
/*   Updated: 2014/05/18 17:45:14 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_pipe(t_tree *ltree, t_tree *rtree, char ***ft_env)
{
	int		fd[2];
	pid_t	father;

	if (0 != pipe(fd) || (father = fork()) == -1)
		return (-1);
	else if (father == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		ft_rdtree(ltree, ft_env);
		close(fd[1]);
		exit(0);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		ft_rdtree(rtree, ft_env);
		close(fd[0]);
		exit(0);
	}
	return (0);
}

int		ft_redir1(t_tree *ltree, t_tree *rtree, char ***ft_env)
{
	int		fd;
	char	*file;

	if (!rtree->cmd)
		return (ft_putstr("éviter les multi-operateurs\n"), -1);
	file = rtree->cmd[0];
	if (access(file, F_OK) == 0 && access(file, W_OK) != 0)
		return (ft_printf("permission denied : %s\n", file), -1);
	fd = open(file, O_RDWR | O_CREAT, S_IRWXU | S_IRWXG);
	dup2(1, fd);
	ft_rdtree(ltree, ft_env);
	return (0);
}


int		ft_redir2(t_tree *ltree, t_tree *rtree, char ***ft_env)
{
	int		fd;
	char	*file;

	if (!rtree->cmd)
		return (ft_putstr("éviter les multi-operateurs\n"), -1);
	file = rtree->cmd[0];
	if ((fd = open(file, O_RDONLY)) == -1)
		return (ft_printf("open failed : %s\n", file), -1);
	dup2(0, fd);
	ft_rdtree(ltree, ft_env);
	return (0);
}
