 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 18:28:54 by ibakayok          #+#    #+#             */
/*   Updated: 2013/12/30 21:50:58 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <sys/types.h>
#include "pipex.h"

int		ft_exec(t_pipex bag)
{
	pid_t	father;
	int		fd[2];

	if (0 != pipe(fd))
		return (-1);
	father = fork();
	if (father == -1)
		return (-1);
	else if (father == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		dup2(bag.fd_input, 0);
		execve(bag.path, bag.lpipe, NULL);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		dup2(bag.fd_output, 1);
		execve(bag.path2, bag.rpipe, NULL);
	}
	return (0);
}
