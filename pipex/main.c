/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 17:54:27 by ibakayok          #+#    #+#             */
/*   Updated: 2013/12/31 17:29:08 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/includes/libft.h"

int		main(int argc, char **argv)
{
	int		p;

	if (argc != 5)
	{
		write(2, "right use : file1 cm1 cmd2 file2\n", 34);
		return (-1);
	}
	if ((p = ft_findpath()) == -1)
	{
		environ[1] = custom_path();
		p = 1;
	}
	return (ft_interpreteur(argv, p));
}
