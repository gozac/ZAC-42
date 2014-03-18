/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Notabspace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 16:59:00 by ibakayok          #+#    #+#             */
/*   Updated: 2014/02/16 17:07:07 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tab_spa(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * ft_strlen(str));
	while (*str)
	{
		if (*str == ' ' || *str == '	')
			str++;
		else
		{
			tmp[i] = *str;
			i++;
			str++;
		}
	}
	tmp[i] = '\0';
	return (tmp);
}
