/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 18:08:36 by ibakayok          #+#    #+#             */
/*   Updated: 2016/03/06 20:12:19 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
			if (ft_strcmp((argv)[i - 1], (argv)[i]) > 0)
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

t_wd	*idx_lst(t_wd *tri, int i)
{
	while (tri && i-- > 0)
		tri = tri->next;
	return (tri);
}

void	swp_list(t_wd **tri1, t_wd **tri2)
{
	t_wd	*tmp;

	if (*tri2 == NULL && *tri1 == NULL)
		return ;
	if (*tri2 == NULL)
	{
		*tri2 = *tri1;
		*tri1 = NULL;
	}
	if (*tri2 == NULL)
	{
		*tri1 = *tri2;
		*tri2 = NULL;
	}
	*tmp = ;
	(tri1)->str = tri2->str;
	(tri1)->dad = tri2->dad;
	(tri1)->s = tri2->s;
	(tri1)->i = tri2->i;
}

int ft_strlstcmp(t_wd *tri1, t_wd *tri2)
{
	if (!tri1 && !tri2)
		return (0);
	if (!tri2)
		return (ft_strcmp(tri1->str, NULL));
	if (!tri1)
		return (ft_strcmp(NULL, tri2->str));
	return (ft_strcmp(tri1->str, tri2->str));
}

t_wd	*tri_list(t_wd *tri, size_t n)
{
	t_wd	*tmp;
	t_wd	*tmp1;
	t_wd	*tmp2;
	size_t	i;
	int		swap;

	swap = 1;
	tmp = NULL;
	while (swap == 1)
	{
		i = 1;
		swap = 0;
		while (i++ < (n))
		{
			tmp1 = idx_lst(tri, i - 1);
			tmp2 = idx_lst(tri, i);
			//ft_printf("start\n");
			if (ft_strlstcmp(idx_lst(tri, i - 1), idx_lst(tri, i)) > 0)
			{
				swp_list(&tmp1, &tmp2);
				swap = 1;
			}
		}
	}
	//ft_printf("end2\n");
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
