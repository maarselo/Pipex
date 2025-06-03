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

// I put two if, for the same infile type, because i the case its the first file
// i have to modify the stdin 

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

void	ft_error()
{
	perror("\033[31mError\033[0m");
	exit(EXIT_FAILURE);
}

void	ft_error_command()
{
	perror("\033[31mError command\033[0m");
	exit(127);
}
