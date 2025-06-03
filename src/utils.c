/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:18:24 by mvillavi          #+#    #+#             */
/*   Updated: 2025/05/26 17:18:25 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_command(void)
{
	perror("\033[31mError command\033[0m");
	exit(127);
}

static void	ft_free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

static char	**ft_split_path_variable(char **envp)
{
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH", 4) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	return (ft_split(envp[i] + 5, ':'));
}

static char	*ft_find_path(char *command, char **envp)
{
	int		i;
	char	*tmp;
	char	*possible_path;
	char	**path;

	if (access(command, X_OK) == 0)
		return (ft_strdup(command));
	path = ft_split_path_variable(envp);
	if (!path)
		ft_error();
	i = -1;
	while (path[++i])
	{
		tmp = ft_strjoin(path[i], "/");
		possible_path = ft_strjoin(tmp, command);
		free (tmp);
		if (access(possible_path, X_OK) == 0)
		{
			ft_free_split(path);
			return (possible_path);
		}
		free(possible_path);
	}
	return (ft_free_split(path), NULL);////////
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
		ft_error_command();
	}
	if (execve(path, split_command, envp) == -1)
	{
		free(path);
		ft_free_split(split_command);
		ft_error_command();
	}
}
