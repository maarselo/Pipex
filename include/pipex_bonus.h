/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:50:49 by mvillavi          #+#    #+#             */
/*   Updated: 2025/05/29 14:50:50 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../Libft/libft.h"
# include "./pipex.h"
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>

# define HEREDOC_OUTFILE "heredoc"
# define INFILE	"infile"
# define OUTFILE "outfile"

void	ft_error(void);
void	ft_execute(char *command, char **envp);

int		ft_open_file(char *file, const char *type);
void	ft_heredoc(char **argv);
void	ft_child_process(char *command, char **envp);

#endif