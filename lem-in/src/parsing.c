/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 15:59:17 by ibakayok          #+#    #+#             */
/*   Updated: 2014/03/18 19:52:07 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

t_tup	*add_tupbis(t_tup *tmp, char *str)
{
	if (tmp == NULL)
	{
		tmp = (t_tup *)malloc(sizeof(t_tup));
		tmp->name = str;
	}
	else
		tmp->next = add_tupbis(tmp->next, str);
	return (tmp);
}

int		add_tuple(t_env **env, char *line)
{
	char	*tmp;
	t_env	*stup;

	stup = *env;
	tmp = ft_xtiret(line, 1);
	if (*env == NULL)
		return (write(2, "Error : Wrong Tuple\n", 24), -1);
	else
	{
		while (*env)
		{
			if (ft_strcmp((*env)->name, tmp) == 0)
				(*env)->tup = add_tupbis((*env)->tup, ft_xtiret(line, 2));
			(*env) = (*env)->next;
		}
		*env = stup;
		while (*env)
		{
			if (ft_strcmp((*env)->name, ft_xtiret(line, 2)) == 0)
				(*env)->tup = add_tupbis((*env)->tup, tmp);
			(*env) = (*env)->next;
		}
	}
	*env = stup;
	return (0);
}

int		add_lab(t_env **env, char *line, int *p, int nb)
{
	if (line[0] == 'L'|| is_tiret(line) > 0)
		return (-1);
	if (*env == NULL)
	{
		(*env) = (t_env *)malloc(sizeof(t_env));
		(*env)->name = ft_xword(line, 1);
		(*env)->nb = 0;
		if (*p == 1)
			(*env)->nb = nb;
		(*env)->stat = *p;
		(*env)->tup = NULL;
		(*env)->next = NULL;
	}
	else
		add_lab(&((*env)->next), line, p, nb);
	*p = 0;
	return (0);
}

int		isstats(char *line, int *p)
{
	if (ft_strcmp(line, "##start") == 0)
	{
		*p = 1;
		return (1);
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		*p = 2;
		return (2);
	}
	return (0);
}

t_env	*mk_env(t_env *anthill, int p, char *line)
{
	int			nb;

	if (ft_isalldigit(line) == 1 && ft_printf("%s\n", line))
	{
		nb = ft_atoi(line);
		while (p != 5 && get_next_line(0, &line) && ft_printf("%s\n", line))
		{
			if (isstats(line, &p) == 0 && line[0] != '#')
			{
				if (is_tiret(line) == 1 && add_tuple(&anthill, line) != -1)
					p = 5;
				else if (add_lab(&anthill, line, &p, nb) == -1)
					return (write(2, "Error : Wrong room name\n", 24), NULL);
			}
		}
		while (get_next_line(0, &line) && ft_printf("%s\n", line) && p != 6)
		{
				if (line[0] != '#'
					&& (is_tiret(line) != 1 || add_tuple(&anthill, line) == -1))
					p = 6;
		}
		return (anthill);
	}
	return (write(2, "Error : No antnumber\n", 21), NULL);
}
