/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 18:08:36 by ibakayok          #+#    #+#             */
/*   Updated: 2015/03/06 17:35:51 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*char	**add_to(char *str, char **tbl)
{

}*/

char	**tri_argv(char **argv, size_t n)
{
	char	*tmp;
	size_t	i;
	int		swap;

	swap = 1;
	while (swap == 1)
	{
		i = 1;
		swap = 0;
		while (i < (n))
		{
			if (ft_strcmp((argv)[i - 1], (argv)[i]) > -1)
			{
				tmp = (argv)[i - 1];
				(argv)[i - 1] = (argv)[i];
				(argv)[i] = tmp;
				swap = 1;
			}
			i++;
		}
	}
	return (argv);
}

t_wd	*index_lst(t_wd *tri, int i)
{
	while (tri && i-- > 0)
		tri = tri->next;
	return (tri);
}

void	cpy_list(t_wd **tri1, t_wd *tri2)
{
	(*tri1)->str = tri2->str;
	(*tri1)->dad = tri2->dad;
	(*tri1)->s = tri2->s;
	(*tri1)->i = tri2->i;
}

t_wd	*tri_list(t_wd *tri, size_t n)
{
	t_wd	*tmp;
	t_wd	*tmp1;
	t_wd	*tmp2;
	size_t	i;
	int		swap;

	swap = 1;
	while (swap == 1)
	{
		i = 1;
		swap = 0;
		while (i < (n))
		{
			tmp1 = index_lst(tri, i - 1);
			tmp2 = index_lst(tri, i);
			if (ft_strcmp(index_lst(tri, i - 1)->str, index_lst(tri, i)->str) > -1)
			{
				cpy_list(&tmp, tmp1);
				cpy_list(&tmp1, tmp2);
				cpy_list(&tmp2, tmp);
				swap = 1;
			}
			i++;
		}
	}
	return (tri);
}

int		main(int argc, char **argv)
{
	int		i;
	t_opt	option;

	i = 1;
	option = ini_opt(option);
	while (is_option(argv[i]) == 2)
		option = chr_option(option, argv[i++]);
	if (argc == i)
		return (list_dir(option, "."));
	option.words = tri_argv(&argv[i], (argc - i));
	if (argc > i + 1)
		option.multi = 1;
	i = 0;
	while (option.words[i])
	{
		if (option.multi == 1)
			ft_printf("%s:\n", option.words[i]);
		if (list_dir(option, option.words[i]) == -1)
			return (-1);
		i++;
		if (option.words[i])
			ft_printf("\n");
	}
	return (0);
}
