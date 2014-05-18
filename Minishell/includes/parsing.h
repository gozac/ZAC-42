/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:31:02 by ibakayok          #+#    #+#             */
/*   Updated: 2014/04/27 21:32:01 by ibakayok         ###   ########.fr       */
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
	struct s_list	*next;
}				t_list;

typedef struct	s_node
{
	int				type;
	char			**cmd;
	struct s_node	*left;
	struct s_node	*right;
}				t_tree;

typedef struct	s_tmp
{
	int		i;
	int		ret;
	char	**bis;
	int		n;
	int		b;
}				t_tmp;

#endif
