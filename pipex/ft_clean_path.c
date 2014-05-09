/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 19:19:20 by ibakayok          #+#    #+#             */
/*   Updated: 2013/12/30 19:19:55 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/includes/libft.h"

char	**ft_clean_path(char *path)
{
	char	**pathway;

	path = path + 5;
	pathway = ft_strsplit(path, ':');
	return (pathway);
}
