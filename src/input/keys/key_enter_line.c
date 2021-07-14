/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_enter_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 21:26:10 by telron            #+#    #+#             */
/*   Updated: 2021/06/28 03:29:11 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inp_keys_enter_line(t_shell *config)
{
	int		exit_code;
	size_t	count_line;

	count_line = ft_inp_get_mode_digit(config, 1);
	write(config->view.fd_dev_tty, "\r", 1);
	ft_up(&config->view, config->view.draw.height);
	exit_code = ft_run_cmd_lines(config, count_line, 0);
	if (!exit_code)
		write(config->view.fd_dev_tty, "\033[46m↴\033[0m\n", 13);
	else
		write(config->view.fd_dev_tty, "\033[41m↴\033[0m\n", 13);
	write(config->view.fd_dev_tty, "\r", 1);
	config->view.draw.height = 0;
}
