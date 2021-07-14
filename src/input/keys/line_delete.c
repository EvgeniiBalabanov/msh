/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 00:00:54 by telron            #+#    #+#             */
/*   Updated: 2021/06/21 04:25:42 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_delete_lines(\
						t_command *command, \
						t_dlist *dlist, \
						size_t count_line)
{
	while (dlist && count_line--)
	{
		if (dlist->right)
			command->cmd_line = dlist->right->content;
		else
		{
			command->cmd_line = 0;
			if (dlist->left)
				command->cmd_line = dlist->left->content;
			count_line = 0;
		}
		ft_dlstrelation(dlist->left, dlist->right);
		ft_inp_cmd_line_delone(dlist->content);
		command->count_cmd_lines--;
		dlist = &command->cmd_line->transport;
	}
}

void	ft_inp_keys_line_delete(t_shell *config)
{
	t_dlist		*dlist;
	size_t		count_line;
	t_command	*command;

	command = ft_inp_command_get(config);
	dlist = &command->cmd_line->transport;
	count_line = ft_inp_get_mode_digit(config, 1);
	ft_inp_keys_line_to_clipboard(config);
	ft_delete_lines(command, dlist, count_line);
	if (!command->count_cmd_lines)
		ft_inp_cmd_line_new(command);
}
