/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 01:16:10 by telron            #+#    #+#             */
/*   Updated: 2021/06/09 00:58:51 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inp_keys_cursor_up(t_shell *config)
{
	t_command	*command;
	size_t		count_line;

	count_line = ft_inp_get_mode_digit(config, 1);
	command = ft_inp_command_get(config);
	while (command->cmd_line->transport.left && count_line--)
		command->cmd_line = \
					(t_cmd_line *)command->cmd_line->transport.left->content;
}
