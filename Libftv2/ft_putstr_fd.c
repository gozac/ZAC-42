/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 15:43:03 by ibakayok          #+#    #+#             */
/*   Updated: 2015/02/03 17:13:17 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

void	ft_putstr_fd(char const *str, int fd)
{
	int		i;

	i = 0;
	if (str == NULL)
		ft_putstr_fd("(null)", fd);
	else
	{
		while (*str)
		{
			write(fd, str, 1);
			str++;
			i++;
		}
	}
}
