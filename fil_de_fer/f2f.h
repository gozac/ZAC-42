/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f2f.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 17:54:37 by ibakayok          #+#    #+#             */
/*   Updated: 2013/12/22 19:33:39 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef list_h
# define list_h

# include <string.h>
# include <stdlib.h>
# include "get_next_line.h"

typedef struct s_list	t_list;

struct 		s_list
{
	int		x;
	int 	y;
	int 	z;
	int 	rx;
	int 	ry;
	t_list	*next;
};

typedef struct 	s_dingue
{
	int			x;
	int			y;
	int			xf;
	int			yf;
	int 		z;
	int			xup;
	int			yup;
	int			rx;
	int			ry;
}				t_dingue;

t_list	*add_list(t_list *list, int z, int x, int y);
t_list	*make_grid(int fd);
int		is_good(t_list *list, int x, int y);
void	rely_point(void *mlx, void *win, t_list *grid);
int		findx(t_list *list, int rx, int ry);
int		findy(t_list *list, int rx, int ry);
void	trace_seg(void *mlx, void *win, t_dingue dingue, int z);
void	trace_seg2(void *mlx, void *win, t_dingue dingue, int z);
void	trace_seg3(void *mlx, void *win, t_dingue dingue, int z);
void	trace_seg4(void *mlx, void *win, t_dingue dingue, int z);

#endif
