/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 20:32:04 by ibakayok          #+#    #+#             */
/*   Updated: 2015/02/03 17:08:36 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreverse(char *s)
{
	char	c;

	c = *s;
	if (!s || !(*s))
		return (NULL);
	else
		return (ft_strcat(ft_strreverse(++s), &c));
}
