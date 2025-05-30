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

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	fdout;

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
		dup2(fdout, STDOUT_FILENO);
		close(fdout);
		ft_execute(argv[argc - 2], envp);
	}
	else
		ft_error();
}
