/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:56:16 by mvillavi          #+#    #+#             */
/*   Updated: 2025/02/26 18:48:28 by mvillavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	ft_putchar_c(char c, int *count);
void	ft_putstr_c(char *s, int *count);
void	ft_putnbr_base(long num, char *base, int *count);
void	ft_putnbr_ulbase(unsigned long num, char *base, int *count);
void	ft_putptr(void *num, int *count);

int		ft_printf(char const *s, ...);
void	ft_format(char const *s, va_list va, int *count);
#endif
