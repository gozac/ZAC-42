/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 16:56:47 by ibakayok          #+#    #+#             */
/*   Updated: 2015/02/04 17:39:21 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		new->content_size = 0;
		new->content = NULL;
	}
	else
	{
		new->content_size = content_size;
		new->content = ft_memalloc();
		new->content = ft_memcpy(new->content, content, content_size);
	}
	new->next = NULL;
	return (new);
}