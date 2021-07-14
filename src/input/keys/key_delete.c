/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 03:40:55 by telron            #+#    #+#             */
/*   Updated: 2021/06/08 10:15:33 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_concat_lines(t_command *command)
{
	t_cmd_line	*left_cmd_line;
	t_cmd_line	*for_free;

	left_cmd_line = \
				(t_cmd_line *)command->cmd_line->transport.left->content;
	command->xx_cursor = left_cmd_line->line->length;
	ft_line_add_line(\
		left_cmd_line->line, \
		command->cmd_line->line);
	ft_dlstrelation(command->cmd_line->transport.left, \
										command->cmd_line->transport.right);
	for_free = command->cmd_line;
	command->cmd_line = command->cmd_line->transport.left->content;
	ft_inp_cmd_line_delone(for_free);
	command->count_cmd_lines--;
}

void	ft_inp_keys_delete(t_shell *config)
{
	t_command	*command;

	ft_inp_cursor_sync(config);
	command = ft_inp_command_get(config);
	if (command->xx_cursor)
	{
		ft_line_del_chr(ft_inp_cmd_line_get(config)->line, \
														command->xx_cursor - 1);
		command->xx_cursor--;
	}
	else if (command->cmd_line->transport.left)
		ft_concat_lines(command);
}
