/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 19:34:07 by ibakayok          #+#    #+#             */
/*   Updated: 2014/04/27 21:26:07 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <sys/types.h>
#include "shell.h"

int		ft_exec(char *path, char **argv, char **ft_env)
{
	pid_t	father;

	if (access(path, X_OK) == -1)
		return (-1);
	father = fork();
	if (father == 0)
	{
		execve(path, argv, ft_env);
		exit (0);
	}
	if (father > 0)
		waitpid(father, 0, 0);
	return (0);
}
