/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 16:58:54 by ibakayok          #+#    #+#             */
/*   Updated: 2014/05/18 17:15:47 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_rdtree(t_tree *tree, char ***ft_env)
{
	if (!tree)
		return (0);
	if (tree->type == 0)
	{
		if (tree && built_in(tree->cmd, ft_env) == 1)
			ft_interpreteur(tree->cmd, *ft_env);
	}
	else if (tree->type == 2)
		ft_pipe(tree->left, tree->right, ft_env);
	else if (tree->type == 4)
		ft_redir1(tree->left, tree->right, ft_env);
	else if (tree->type == 3)
		ft_redir2(tree->left, tree->right, ft_env);
	else
	{
		ft_rdtree(tree->left, ft_env);
		ft_rdtree(tree->right, ft_env);
	}
	return (1);
}

char	**new_env(char **environ)
{
	char	**tmp;
	int		i;

	i = 0;
	while (environ[i] != '\0')
		i++;
	tmp = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (environ[++i] != '\0')
		tmp[i] = ft_strdup(environ[i]);
	tmp[i] = '\0';
	return (tmp);
}

t_tree	*grow_seed(char *line)
{
	t_list	*list;
	t_tree	*parsing;

	list = lexer(line);
	parsing = get_tree(list);
	return (parsing);
}

int		main(int argc, char **argv, char **environ)
{
	t_tree	*parsing;
	char	**ft_env;
	char	*line;

	(void)argc;
	(void)argv;
	ft_env = new_env(environ);
	parsing = NULL;
	ft_printf("$> ");
	while (get_next_line(0, &line))
	{
		parsing = grow_seed(line);
		ft_rdtree(parsing, &ft_env);
		ft_printf("$> ");
	}
	return (0);
}
