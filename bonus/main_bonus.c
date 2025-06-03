/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:50:21 by mvillavi          #+#    #+#             */
/*   Updated: 2025/05/29 14:50:22 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* In the ft_heredoc function and in the other if above, the second file
ft_open it does not return anything because in the same function it formats
the stdin itself*/
#include "pipex_bonus.h"

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
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}
int	ft_last_command(int fdout, char *command, char **envp)
{
	int	status;
	pid_t	pid;

	dup2(fdout, STDOUT_FILENO);
	close(fdout);
	pid = fork();
	if (pid == -1)
		ft_error();
	if (pid == 0)
		ft_execute(command, envp);
	waitpid(pid, &status, 0 );
	return (WEXITSTATUS(status));
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		fdout;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8))
		{
			i = 2;
			fdout = ft_open_file(argv[argc - 1], OUTFILE);
			ft_open_file(argv[1], INFILE);
		}
		else
		{
			i = 3;
			fdout = ft_open_file(argv[argc - 1], HEREDOC_OUTFILE);
			ft_heredoc(argv);
		}
		while (i < argc - 2)
			ft_child_process(argv[i++], envp);
		return (ft_last_command(fdout, argv[argc - 2], envp));
	}
	else
		ft_putstr_fd("Error: Invalid arguments.", 2);
}
