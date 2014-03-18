/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:31:02 by ibakayok          #+#    #+#             */
/*   Updated: 2014/03/12 19:57:39 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct	s_list
{
	int				type;
	int				rank;
	char			**cmd;
	struct	s_list	*next;
}				t_list;

typedef struct	node
{
	int				type;
	char			**cmd;
	struct	node	*left;
	struct	node	*right;
}				t_tree;

t_list	*lexer(char *str);
t_tree	*get_tree(t_list *lex);

#endif
