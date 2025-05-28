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
#include <string.h>

static void	ft_child_process(int *fd, char **argv, char **envp)
{
	(void)envp;
	int	filein;

	filein = open(argv[1], O_RDONLY);
	if (filein == -1)
		ft_error();
	close(fd[0]);
	dup2(filein, STDIN_FILENO);
	close(filein);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	char *msg = "Hola desde el hijo\n";
	write(STDOUT_FILENO, msg, strlen(msg));
	exit(0);
}

static void	ft_parent_process(int *fd, char **argv, char **envp)
{
	(void)envp;
	int	fileout;
	char buffer[1000];

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fileout == -1)
		ft_error();
	close(fd[1]);
	dup2(fileout, STDOUT_FILENO);
	close(fileout);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	ssize_t bytes = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
	if (bytes > 0)
	{
		buffer[bytes] = '\0';
		printf("Padre recibió: %s", buffer);
	}
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (argc == 5) 	
	{
		if (pipe(fd) == -1)
			ft_error();
		pid = fork();
		if (pid == -1)
			ft_error();
		if (pid == 0)
			ft_child_process(fd, argv, envp);
		wait(NULL);
		ft_parent_process(fd, argv, envp);
	}
	else
		ft_putstr_fd("Error: Bad arguments.", 2);
	return (0);
}
