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

int	ft_heredoc(int argc, char **argv)
{
	int		fd[2];
	char	*delimiter;
	char	*content;

	if (pipe(fd) == -1)
		ft_error();
	dup2(fd[1],STDOUT_FILENO);
	close(fd[0]);
	delimiter = argv[2];
	content = get_next_line(0);
	while (content && ft_strncmp(content, delimiter, ft_strlen(delimiter))
		&& content[ft_strlen(delimiter)] == '\n')
	{
		write(STDOUT_FILENO, content, ft_strlen(content));
		free(content);
		content = get_next_line(0);
	}
	return (fd[0]);fgrggfg
}