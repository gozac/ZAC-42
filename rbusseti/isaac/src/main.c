/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 16:58:54 by ibakayok          #+#    #+#             */
/*   Updated: 2014/03/12 20:03:24 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		main(int argc, char **argv)
{
	t_list	*list;
	t_tree	*parsing;

	parsing = NULL;
	if (argc != 2)
		return (0);
	list = lexer(argv[1]);
	parsing = get_tree(list);
	if (parsing)
		sleep(20);
	return (0);
}
