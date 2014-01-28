/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestrtab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 19:30:04 by ibakayok          #+#    #+#             */
/*   Updated: 2013/12/25 19:32:03 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			<stdlib.h>

void	ft_freestrtab(char ***tab)
{
	int				i;

	i = 0;
	while (*tab[i])
	{
		free(*tab[i]);
		*tab[i++] = NULL;
	}
	free(*tab);
	*tab = NULL;
}
