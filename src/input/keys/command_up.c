/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 04:49:27 by telron            #+#    #+#             */
/*   Updated: 2021/06/09 00:20:14 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inp_keys_command_up(t_shell *config)
{
	size_t		count_command;
	t_view		*view;

	view = &config->view;
	count_command = ft_inp_get_mode_digit(config, 1);
	while (view->command->transport.left && count_command--)
	{
		view->command = (t_command *)view->command->transport.left->content;
		view->index_command -= 1;
	}
}
