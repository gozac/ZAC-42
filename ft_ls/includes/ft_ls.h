/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 16:54:34 by ibakayok          #+#    #+#             */
/*   Updated: 2016/03/02 18:27:45 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/stat.h>
# include <errno.h>
# include <stdio.h>
# include <time.h>
# include <grp.h>
# include <pwd.h>
# include "libft.h"
# include "struct.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define SPACE 4
# define REC 15

t_opt	ini_opt(t_opt option);
int		is_option(char *str);
int		stat_dir(t_wd *tri);
t_wd	*add_tri(t_wd *tri, char *name, t_opt option, char *dad);
t_opt	chr_option(t_opt option, char *str);
void	odre_dir(t_opt option, t_wd *tri);
int		list_dir(t_opt option, char *str);
t_wd	*tri_list(t_wd *tri, size_t n);

#endif
