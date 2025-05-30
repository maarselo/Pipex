/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:18:24 by mvillavi          #+#    #+#             */
/*   Updated: 2025/05/30 11:51:03 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

void	ft_error(void)
{
	perror("\033[31mError\033[0m");
	exit(EXIT_FAILURE);
}

static char	*ft_find_path(char *command, char **envp)
{
	int		i;
	char	*tmp;
	char	*path;
	char	**variables;

	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4) != 0)
		i++;
	variables = ft_split(envp[i] + 5, ':');
	i = -1;
	while (variables[++i])
	{
		tmp = ft_strjoin(variables[i], "/");
		path = ft_strjoin(tmp, command);
		free (tmp);
		if (access(path, X_OK) == 0)
		{
			ft_free_split(variables);
			return (path);
		}
		free(path);
	}
	ft_free_split(variables);
	return (NULL);
}

void	ft_execute(char *command, char **envp)
{
	char	**split_command;
	char	*path;

	split_command = ft_split(command, ' ');
	path = ft_find_path(split_command[0], envp);
	if (!path)
	{
		ft_free_split(split_command);
		ft_error();
	}
	if (execve(path, split_command, envp) == -1)
	{
		ft_free_split(split_command);
		ft_error();
	}
}
