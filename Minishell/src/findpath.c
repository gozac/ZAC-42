/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 19:09:59 by ibakayok          #+#    #+#             */
/*   Updated: 2014/02/09 16:29:45 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*mystrndup(const char *s1, size_t n)
{
	size_t	len;
	char	*s2;

	len = ft_strlen(s1) + 1;
	if (len > n)
	{
		if ((s2 = ft_strnew(n)) == NULL)
			return (NULL);
		else
			ft_strncpy(s2, s1, n);
	}
	else
	{
		if ((s2 = ft_strnew(len)) == NULL)
			return (NULL);
		else
			ft_strncpy(s2, s1, len);
	}
	return (s2);
}

int		ft_sc(char *s, int c)
{
	char	ret;
	int		i;

	i = 0;
	ret = (char)c;
	while (s[i] != '\0' && s[i] != ret)
		i++;
	return (i);
}

char	*ft_findpath(char **environ)
{
	int		i;
	char	*p;

	i = 0;
	p = "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/X11/bin:/usr/texbin";
	while (environ[i] != '\0')
	{
		if (!(ft_strcmp(mystrndup(environ[i], ft_sc(environ[i], '=')), "PATH")))
			return (environ[i]);
		i++;
	}
	write(2, "no PATH -> Custom PATH -> done\n", 32);
	return (p);
}
