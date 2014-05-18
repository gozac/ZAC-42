/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 17:34:47 by ibakayok          #+#    #+#             */
/*   Updated: 2014/04/27 21:31:54 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_unsetenv(char *name, char ***ft_env)
{
	t_tmp	t;

	t.b = 0;
	t.n = 0;
	t.i = 0;
	t.ret = -1;
	if (name == NULL)
		return (t.ret);
	while ((*ft_env)[t.b] != '\0')
		t.b++;
	t.bis = (char **)malloc(sizeof(char *) * (t.b - 1));
	t.bis[t.b - 1] = NULL;
	while (t.i < (t.b - 1))
	{
		if (ft_strncmp((*ft_env)[t.n], name, ft_strlen(name)) == 0)
			t.ret = 0;
		else
			t.bis[t.i++] = (*ft_env)[t.n];
		t.n++;
	}
	if (t.ret == -1)
		ft_printf("unsetenv : not in environ : %s\n", name);
	else
		*ft_env = t.bis;
	return (t.ret);
}
