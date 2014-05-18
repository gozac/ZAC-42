/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 16:51:26 by ibakayok          #+#    #+#             */
/*   Updated: 2014/05/18 17:37:27 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
# include <dirent.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "parsing.h"


t_list	*lexer(char *str);
t_tree	*get_tree(t_list *lex);
int		built_in(char **data, char ***ft_env);
int		cd(char **data, char ***ft_env);
int		env(char **ft_env);
int		ft_setenv(char *name, char *value, int overwrite, char ***ft_env);
int		ft_unsetenv(char *name, char ***ft_env);
char	*ft_findpath(char **environ);
char	*search(char *s, char *path);
int		ft_exec(char *path, char **argv, char **ft_env);
int		ft_interpreteur(char **data, char **ft_env);
int		ft_pipe(t_tree *ltree, t_tree *rtree, char ***ft_env);
int		ft_rdtree(t_tree *tree, char ***ft_env);
int		ft_redir1(t_tree *ltree, t_tree *rtree, char ***ft_env);
int		ft_redir2(t_tree *ltree, t_tree *rtree, char ***ft_env);

#endif

