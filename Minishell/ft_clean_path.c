/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 17:06:40 by ibakayok          #+#    #+#             */
/*   Updated: 2013/12/29 17:55:13 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myshell.h"

char	**ft_clean_path(char *path)
{
	char	**pathway;

	path = path + 5;
	pathway = ft_strsplit(path, ':');
	return (pathway);
}
