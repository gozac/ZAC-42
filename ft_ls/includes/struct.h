/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 19:06:02 by ibakayok          #+#    #+#             */
/*   Updated: 2016/03/02 18:07:20 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_opt
{
	int			l;
	int			a;
	int			r;
	int			rec;
	int			t;
	int			i;
	int			multi;
	char		**words;
}				t_opt;

typedef struct	s_wd
{
	char			*str;
	char			*dad;
	struct stat		s;
	int				i;
	struct s_wd		*next;
}				t_wd;

#endif
