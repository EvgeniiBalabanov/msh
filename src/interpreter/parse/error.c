/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 01:45:30 by telron            #+#    #+#             */
/*   Updated: 2021/06/25 03:49:14 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_print_error(\
						const char *func_name, \
						const char *message, \
						const char *info)
{
	ft_putstr_fd("msh:", 2);
	if (func_name)
		ft_putstr_fd(func_name, 2);
	ft_putstr_fd(":", 2);
	if (message)
		ft_putstr_fd(message, 2);
	ft_putstr_fd(":", 2);
	if (info)
		ft_putstr_fd(info, 2);
	ft_putendl_fd("", 2);
}

static void	ft_print_error_color(\
						const char *func_name, \
						const char *message, \
						const char *info)
{
	write(2, "\033[1;31mmsh\033[1;35m:\033[1;34m", 25);
	if (func_name)
		write(2, func_name, ft_strlen(func_name));
	write(2, "\033[1;35m:\033[1;37m", 15);
	if (message)
		write(2, message, ft_strlen(message));
	write(2, "\033[1;35m:\033[1;34m", 15);
	if (info)
		write(2, info, ft_strlen(info));
	write(2, "\033[m\n", 4);
}

void	ft_error_print(\
						t_shell __attribute__((unused)) *config, \
						const char *func_name, \
						const char *message, \
						const char *info)
{
	if (ft_isatty(2))
		ft_print_error_color(func_name, message, info);
	else
		ft_print_error(func_name, message, info);
}
