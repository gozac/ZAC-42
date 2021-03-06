/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 18:51:01 by ibakayok          #+#    #+#             */
/*   Updated: 2015/02/04 18:52:33 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list * ft_lstmap(t_list *lst, t_list * (*f)(t_list *elem))
{
	
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
}