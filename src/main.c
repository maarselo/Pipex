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

static void	ft_child_process(char **argv, int *fd, char *envp) {
	int file;
	
	file = open(argv[1], O_RDONLY);
	if (file != -1)
		ft_error();
	

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
			ft_child_process(argv, &fd, envp);
		wait(NULL);
	}
	else
		ft_putstr_fd("Error: Bad arguments.", 2);
	return (0);
}
