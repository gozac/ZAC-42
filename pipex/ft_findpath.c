/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 16:36:29 by ibakayok          #+#    #+#             */
/*   Updated: 2013/12/31 17:06:40 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/includes/libft.h"

char	*ft_strndup(const char *s1, size_t n)
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

int		ft_findpath(void)
{
	int		i;

	i = 0;
	while (environ[i] != '\0')
	{
		if (ft_strcmp(ft_strndup(environ[i], ft_sc(environ[i], '=')), "PATH")
			== 0)
			return (i);
		i++;
	}
	write(2, "no PATH -> Custom PATH -> done\n", 34);
	return (-1);
}
