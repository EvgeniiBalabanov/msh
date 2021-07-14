/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 05:09:24 by telron            #+#    #+#             */
/*   Updated: 2021/06/09 00:04:06 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inp_keys_command_down(t_shell *config)
{
	size_t		count_command;

	count_command = ft_inp_get_mode_digit(config, 1);
	while (config->view.command->transport.right && count_command--)
	{
		config->view.command = \
				(t_command *)config->view.command->transport.right->content;
		config->view.index_command += 1;
	}
}
