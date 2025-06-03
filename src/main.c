/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:09:15 by mvillavi          #+#    #+#             */
/*   Updated: 2025/05/13 16:09:16 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(void)
{
	perror("\033[31mError\033[0m");
	exit(EXIT_FAILURE);
}

static void	ft_child_process(int *fd, pid_t pid, char **argv, char **envp)
{
	int	filein;

	if (pid == -1)
		ft_error();
	if (pid != 0)
		return ;
	filein = open(argv[1], O_RDONLY);
	if (filein == -1)
		ft_error();
	close(fd[0]);
	dup2(filein, STDIN_FILENO);
	close(filein);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	ft_execute(argv[2], envp);
}

static void	ft_parent_process(int *fd, pid_t pid, char **argv, char **envp)
{
	int	fileout;

	if (pid == -1)
		ft_error();
	if (pid != 0)
		return ;
	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fileout == -1)
		ft_error();
	close(fd[1]);
	dup2(fileout, STDOUT_FILENO);
	close(fileout);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	ft_execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		status;
	int		fd[2];

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error();
		pid = fork();
		ft_child_process(fd, pid, argv, envp);
		pid = fork();
		ft_parent_process(fd, pid, argv, envp);
		close(fd[0]);/////////////
		close(fd[1]);////////////////
		waitpid(pid, &status, 0);////////////////////
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}
	else
		ft_putstr_fd("Error: Invalid arguments.", 2);
}
