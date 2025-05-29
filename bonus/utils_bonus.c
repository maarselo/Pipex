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

void	ft_child_process(char *command, char **envp)
{
	pid_t	pid;

	pid = fork();
	//if ()
}
int	ft_open_file(char *file, const char *type)
{
	int	fd;

	if (!ft_strncmp(type, "heredoc", ft_strlen(type)))
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0644);
	else if (!ft_strncmp(type, "infile", ft_strlen(type)))
		fd = open(file, O_RDONLY);
	else if (!ft_strncmp(type, "outfile", ft_strlen(type)))
		fd = open (file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		ft_error();	
	return (fd);
}


void	ft_heredoc(int argc, char **argv)
{
	int		fd[2];
	char	*delim;
	char	*content;

	if (pipe(fd) == -1)
		ft_error();
	delim = argv[2];
	content = get_next_line(0);
	while (content)
	{
		if (!ft_strncmp(content, delim, ft_strlen(delim)) 
			&& content[ft_strlen(delim)] == '\n')
		{
			free(content);
			break;
		}
		write(fd[1], content, ft_strlen(content));
		free(content);
		content = get_next_line(0);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
}