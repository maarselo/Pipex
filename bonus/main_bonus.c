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
	if (argc >= 5)
	{
		if (!ft_strncmp(argv[1], "here_doc", 8))
		{
			ft_heredoc(argc, argv);
		}
	}

}