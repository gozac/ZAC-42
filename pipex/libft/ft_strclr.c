/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-segu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:11:11 by sde-segu          #+#    #+#             */
/*   Updated: 2013/12/08 22:36:46 by sde-segu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_strclr(char *s)
{
	int		i;

	i = 0;
	if (s == 0)
		return ;
	while (s[i] != '\0')
	{
		s[i] = '\0';
		i++;
	}
}