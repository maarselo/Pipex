/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:18:24 by mvillavi          #+#    #+#             */
/*   Updated: 2025/05/30 11:51:03 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	ft_error(void)
{
	perror("\033[31mError\033[0m");
	exit(EXIT_FAILURE);
}

void	ft_error_command(void)
{
	perror("\033[31mError command\033[0m");
	exit(127);
}
