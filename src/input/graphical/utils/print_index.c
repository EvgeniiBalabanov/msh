/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:43:26 by aberry            #+#    #+#             */
/*   Updated: 2021/06/28 03:29:11 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_index(t_shell *config, size_t index)
{
	size_t	counter;
	size_t	count;

	counter = 0;
	count = ft_inp_command_get(config)->len_prefix - \
							ft_inp_get_length_number(index) - 4;
	while (counter < count)
	{
		write(config->view.fd_dev_tty, " ", 1);
		counter++;
	}
	write(config->view.fd_dev_tty, "[", 1);
	if (COLOR_DIGIT)
		write(config->view.fd_dev_tty, \
			COLOR_DIGIT, ft_strlen(COLOR_DIGIT));
	ft_putnbr_fd(index, config->view.fd_dev_tty);
	if (COLOR_DIGIT)
		write(config->view.fd_dev_tty, \
			COLOR_NORMAL, ft_strlen(COLOR_NORMAL));
	write(config->view.fd_dev_tty, "]> ", 3);
}
