/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 17:39:36 by ibakayok          #+#    #+#             */
/*   Updated: 2015/02/04 18:38:23 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*next;

	if (alst != NULL)
	{
		tmnp = *alst;
		next = *alst->next;
		while (tmp != NULL)
		{
			ft_lstdelone(&tmp, del);
			tmp = next;
			next = next->next;
		}
		*alst = NULL;
	}

}