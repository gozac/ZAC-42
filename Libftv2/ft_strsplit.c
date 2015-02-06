/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 19:20:57 by ibakayok          #+#    #+#             */
/*   Updated: 2014/01/19 21:38:22 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int		word;
	int		i;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			word++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (word);
}

static int	ft_len_word(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		j;
	int		len;
	int		word;

	j = -1;
	if (s == NULL)
		return (NULL);
	word = ft_count_word(s, c);
	if ((tab = (char **)malloc(sizeof(char *) * (word + 1))) == NULL)
		return (NULL);
	while (++j < word)
	{
		while (*s != '\0' && *s == c)
			s++;
		len = ft_len_word(s, c);
		if ((tab[j] = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		ft_strncpy(tab[j], s, len);
		while (*s != '\0' && *s != c)
			s++;
	}
	tab[j] = NULL;
	return (tab);
}
