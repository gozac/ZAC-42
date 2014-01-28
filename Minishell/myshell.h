/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myshell.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 18:48:21 by ibakayok          #+#    #+#             */
/*   Updated: 2013/12/29 23:10:11 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYSHELL_H
# define MYSHELL_H

# include <dirent.h>
# include "libft/includes/libft.h"
# include "get_next_line.h"

extern char	**environ;

int		env(char **ft_env);
int		cd(char **data, char ***ft_env);
int		ft_interpreteur(char **data);
char	*search(const char *s, char *path);
char	**ft_clean_path(char *path);
int		ft_exec(char *path, char **argv);
int		built_in(char **data, char ***ft_env);
int		ft_setenv(char *name, char *value, int overwrite, char ***ft_env);
int		ft_unsetenv(char *name, char ***ft_env);

#endif
