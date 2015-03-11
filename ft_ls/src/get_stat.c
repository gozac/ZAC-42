/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 16:18:01 by ibakayok          #+#    #+#             */
/*   Updated: 2015/03/10 18:21:08 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	prot_dir(mode_t data)
{
	if (((data) & S_IFMT) == S_IFREG)
		ft_printf("-");
	else if (((data) & S_IFMT) == S_IFCHR)
		ft_printf("c");
	else if (((data) & S_IFMT) == S_IFDIR)
		ft_printf("d");
	else if (((data) & S_IFMT) == S_IFBLK)
		ft_printf("b");
	else if (((data) & S_IFMT) == S_IFLNK)
		ft_printf("l");
	else if (((data) & S_IFMT) == S_IFSOCK)
		ft_printf("s");
	else if (((data) & S_IFMT) == S_IFIFO)
		ft_printf("p");
	else
		ft_printf("?");
	(data) & S_IRUSR ? ft_printf("r") : ft_printf("-");
	(data) & S_IWUSR ? ft_printf("w") : ft_printf("-");
	(data) & S_IXUSR ? ft_printf("x") : ft_printf("-");
	(data) & S_IRGRP ? ft_printf("r") : ft_printf("-");
	(data) & S_IWGRP ? ft_printf("w") : ft_printf("-");
	(data) & S_IXGRP ? ft_printf("x") : ft_printf("-");
	(data) & S_IROTH ? ft_printf("r") : ft_printf("-");
	(data) & S_IWOTH ? ft_printf("w") : ft_printf("-");
	(data) & S_IXOTH ? ft_printf("x") : ft_printf("-");
}

void	prt_lsnb(int p)
{
	int		d;
	int		i;
	int		n;

	i = 0;
	d = p;
	while (d >= 10)
	{
		i++;
		d = d / 10;
	}
	n = SPACE - i;
	while (n > 0)
		ft_printf(" ", n--);
	ft_printf("%d ", p);
}

int		stat_dir(t_wd *tri)
{
	struct group	*grid;
	struct passwd	*pwid;

	prot_dir(tri->s.st_mode);
	prt_lsnb((unsigned)tri->s.st_nlink);
	if ((pwid = getpwuid(tri->s.st_uid)))
		ft_printf("%s ", pwid->pw_name);
	else
		write(1, "NULL ", 5);
	if ((grid = getgrgid(tri->s.st_gid)))
		ft_printf(" %s ", grid->gr_name);
	else
		write(1, "NULL ", 5);
	prt_lsnb((unsigned)tri->s.st_size);
	write(1, ctime(&tri->s.st_mtime) + 4, 12);
	write(1, " ", 1);
	return (0);
}
