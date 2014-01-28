/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 18:28:28 by ibakayok          #+#    #+#             */
/*   Updated: 2013/12/29 18:52:55 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <sys/types.h>
#include "myshell.h"

int		ft_exec(char *path, char **argv)
{
	pid_t	father;

	if (access(path, X_OK) == -1)
		return (-1);
	father = fork();
	if (father == 0)
	{
		execve(path, argv, environ);
		exit (0);
	}
	if (father > 0)
		waitpid(father, 0, 0);
	return (0);
}
