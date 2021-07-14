/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classic_enter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 07:40:22 by telron            #+#    #+#             */
/*   Updated: 2021/06/08 10:15:33 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inp_keys_classic_enter(t_shell *config)
{
	t_cmd_line	*cmd_line;
	t_cmd_line	*cmd_line_right;
	t_command	*command;

	ft_inp_cursor_sync(config);
	cmd_line = ft_inp_cmd_line_get(config);
	command = ft_inp_command_get(config);
	ft_inp_cmd_line_new(command);
	cmd_line_right = (t_cmd_line *)cmd_line->transport.right->content;
	ft_line_add_str(cmd_line_right->line, \
		cmd_line->line->string + command->xx_cursor);
	ft_line_cut_index(cmd_line->line, command->xx_cursor);
	command->cmd_line = cmd_line_right;
	command->xx_cursor = 0;
}
