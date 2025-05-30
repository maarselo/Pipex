/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:50:36 by mvillavi          #+#    #+#             */
/*   Updated: 2025/05/29 14:50:37 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// I put two if, for the same infile type, because i the case its the first file
// i have to modify the stdin 
int	ft_open_file(char *file, const char *type)
{
	int	fd;

	if (!ft_strncmp(type, "heredoc", ft_strlen(type)))
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (!ft_strncmp(type, "outfile", ft_strlen(type)))
		fd = open (file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error();
	if (!ft_strncmp(type, "infile", ft_strlen(type)))
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
		return (STDIN_FILENO);
	}
	return (fd);
}

void	ft_heredoc(char **argv)
{
	int		fd[2];
	char	*delimiter;
	char	*content;

	if (pipe(fd) == -1)
		ft_error();
	delimiter = argv[2];
	write(1, "> ", 2);
	content = get_next_line(0);
	while (content)
	{
		if (!ft_strncmp(content, delimiter, ft_strlen(delimiter))
			&& content[ft_strlen(delimiter)] == '\n')
		{
			free(content);
			break ;
		}
		write(1, "> ", 2);
		write(fd[1], content, ft_strlen(content));
		free(content);
		content = get_next_line(0);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
}

//Deberia de hacer un close del archivo outfile
void	ft_child_process(char *command, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		ft_error();
	pid = fork();
	if (pid == -1)
		ft_error();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		ft_execute(command, envp);
	}
	else
	{
		wait(NULL);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}
