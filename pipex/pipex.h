/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 16:50:51 by sde-segu          #+#    #+#             */
/*   Updated: 2013/12/31 17:30:16 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

extern char	**environ;

typedef struct s_pipex t_pipex;

struct		s_pipex
{
	char	*path;
	char	*path2;
	int		fd_input;
	int		fd_output;
	char	**lpipe;
	char	**rpipe;
};

int			ft_interpreteur(char **data, int p);
int			ft_exec(t_pipex bag);
char		*search(const char *s, char *path);
char		**ft_clean_path(char *path);
int			ft_findpath(void);
char		*custom_path(void);


#endif /*PIPEX_H*/
