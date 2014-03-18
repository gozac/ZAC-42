/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 19:06:49 by ibakayok          #+#    #+#             */
/*   Updated: 2014/03/16 19:25:48 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct	s_tup
{
	char			*name;
	struct s_tup	*next;
}					t_tup;

typedef struct	s_env
{
	char			*name;
	int				stat;
	int				nb;
	t_tup			*tup;
	struct s_env	*next;
}					t_env;

typedef struct	s_ant
{
	int				num;
	char			*pos;
	struct s_ant	*next;
}					t_ant;

typedef struct	s_way
{
	char			*name;
	struct s_way	*next;
}					t_way;

t_env	*mk_env(t_env *anthill, int p, char *line);
t_ant	*mk_ant(t_env *env);
int		found_max(t_env *env);
t_env	*mk_way(t_env *env);
int		mk_move(t_env *way, t_ant **fm);
t_env	*found_stat(t_env *tmp, int p);
t_env	*found_name(t_env *tmp, char *str);

#endif
