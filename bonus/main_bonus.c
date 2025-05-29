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

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	fdin;
	int fdout;

	if (argc >= 5)
	{
		if (!ft_strncmp(argv[1], "here_doc", 8))
		{
			i = 3;
			fdout = ft_open_file(argv[argc - 1], HEREDOC_OUTFILE);
			ft_heredoc(argc, argv);
		}
		else
		{
			i = 2;
			fdin = open(argv[1], O_RDONLY);
			if (open)
			dup2(fdin, STDIN_FILENO);
		}
		while (i < argc -2)
			ft_child_process(argv[i++], envp);
	}

}
