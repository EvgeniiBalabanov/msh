/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 12:04:22 by telron            #+#    #+#             */
/*   Updated: 2021/06/10 12:04:58 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inp_keys_cursor_down(t_shell *config)
{
	t_command	*command;
	size_t		count_line;

	command = ft_inp_command_get(config);
	count_line = ft_inp_get_mode_digit(config, 1);
	while (command->cmd_line->transport.right && count_line--)
		command->cmd_line = \
				(t_cmd_line *)command->cmd_line->transport.right->content;
}
