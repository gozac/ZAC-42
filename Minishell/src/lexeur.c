/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexeur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:32:17 by ibakayok          #+#    #+#             */
/*   Updated: 2014/05/15 14:55:08 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		getrk(int c)
{
	if (c == 1 || c == 8)
		return (0);
	if (c == 7 || c == 9)
		return (1);
	if (c == 2)
		return (2);
	if (c >= 3 && c <= 6)
		return (3);
	return (4);
}

int		isoper(char *c)
{
	if (c[0] == ';')
		return (1);
	if (c[0] == '|')
	{
		if (c[2] == '|')
			return (7);
		return (2);
	}
	if (c[0] == '<')
	{
		if (c[1] == '<')
			return (5);
		return (3);
	}
	if (c[0] == '>')
	{
		if (c[1] == '>')
			return (6);
		return (4);
	}
	if (c[0] == '&')
		return (8);
	return (0);
}

t_list	*get_buffer(t_list *lex, char *s, int c)
{
	if (s[0] == '\0')
		return (ft_printf("probleme de type %d\n", c), lex);
	if (lex == NULL)
	{
		lex = (t_list *)malloc(sizeof(t_list));
		lex->type = 0;
		lex->rank = 4;
		lex->cmd = ft_strsplit(ft_tab_spa(s), ' ');
		if (c != 0)
		{
			lex->next = (t_list *)malloc(sizeof(t_list));
			lex->next->type = c;
			lex->next->rank = getrk(c);
			lex->next->cmd = NULL;
			lex->next->next = NULL;
		}
		else
			lex->next = NULL;
	}
	else
		lex->next = get_buffer(lex->next, s, c);
	return (lex);
}

t_list	*lexer(char *str)
{
	t_list	*ret;
	char	*buffer;
	int		i;

	i = 0;
	ret = NULL;
	buffer = ft_strnew(ft_strlen(str) + 1);
	while (*str != '\0')
	{
		if (isoper(str) > 0)
		{
			ret = get_buffer(ret, buffer, isoper(str));
			ft_strclr(buffer);
			i = -1;
		}
		else
			buffer[i] = *str;
		i++;
		str++;
	}
	if (buffer[0] != 0)
		ret = get_buffer(ret, buffer, 0);
	ft_strdel(&buffer);
	return (ret);
}
