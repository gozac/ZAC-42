/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 19:49:42 by ibakayok          #+#    #+#             */
/*   Updated: 2014/05/18 16:00:02 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_list	*searchrank(t_list *lex, int i)
{
	t_list	*tmp;

	tmp = lex;
	while (tmp)
	{
		if (tmp->rank == i)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_list	*cutlex(t_list *ret, t_list *tmp)
{
	t_list	*bis;

	if (ret == tmp)
		return (NULL);
	while (ret && tmp != ret)
	{
		bis = ret;
		ret = ret->next;
	}
	bis->next = NULL;
	return (bis);
}

t_tree	*addnode(t_list *tmp)
{
	t_tree	*ret;

	ret = NULL;
	if (tmp != NULL)
	{
		ret = (t_tree *)malloc(sizeof(t_tree));
		ret->cmd = tmp->cmd;
		ret->type = tmp->type;
		ret->left = NULL;
		ret->right = NULL;
		free(tmp);
	}
	return (ret);
}

t_tree	*get_tree(t_list *lex)
{
	t_tree	*dad;
	int		i;
	t_list	*op;
	t_list	*after;

	i = 0;
	dad = NULL;
	while (i < 5)
	{
		if ((op = searchrank(lex, i)) != NULL)
		{
			dad = addnode(op);
			if (op->next)
			{
				after = op->next;
				dad->right = get_tree(after);
			}
			lex = cutlex(lex, op);
			dad->left = get_tree(lex);
			i = 5;
		}
		i++;
	}
	return (dad);
}
