/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 15:43:55 by ibakayok          #+#    #+#             */
/*   Updated: 2013/12/08 23:07:24 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*ret;

	if ((ret = (char *) malloc(sizeof(*ret) * (size + 1))) == NULL)
		return (NULL);
	ft_bzero(ret, size + 1);
	return (ret);
}
