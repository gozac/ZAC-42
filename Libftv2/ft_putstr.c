/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 14:21:12 by ibakayok          #+#    #+#             */
/*   Updated: 2015/02/03 16:56:39 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

void	ft_putstr(char const *str)
{
	int		i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		/*return (6);*/
	}
	else
	{
		while (*str)
		{
			write(1, str, 1);
			str++;
			i++;
		}
	}
	/*return (i); */
}
