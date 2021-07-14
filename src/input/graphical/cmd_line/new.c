/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 07:32:43 by telron            #+#    #+#             */
/*   Updated: 2021/06/08 10:15:33 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd_line	*ft_inp_cmd_line_create(void)
{
	t_cmd_line	*cmd_line;

	cmd_line = (t_cmd_line *)ft_calloc(1, sizeof(t_cmd_line));
	if (cmd_line)
		cmd_line->transport.content = cmd_line;
	return (cmd_line);
}

t_cmd_line	*ft_inp_cmd_line_new(t_command *command)
{
	t_line		*line;
	t_cmd_line	*new_cmd_line;

	line = ft_line_create_str("");
	if (!line)
		return ((t_cmd_line *)0);
	new_cmd_line = ft_inp_cmd_line_create();
	if (!new_cmd_line)
	{
		ft_line_del(line);
		return ((t_cmd_line *)0);
	}
	new_cmd_line->line = line;
	if (!command->cmd_line)
		command->cmd_line = new_cmd_line;
	else
		ft_dlstinsert(&command->cmd_line->transport, \
					&new_cmd_line->transport, \
					command->cmd_line->transport.right);
	command->count_cmd_lines += 1;
	return (new_cmd_line);
}

t_cmd_line	*ft_inp_cmd_line_new_up(t_command *command)
{
	t_line		*line;
	t_cmd_line	*new_cmd_line;

	line = ft_line_create_str("");
	if (!line)
		return ((t_cmd_line *)0);
	new_cmd_line = ft_inp_cmd_line_create();
	if (!new_cmd_line)
	{
		ft_line_del(line);
		return ((t_cmd_line *)0);
	}
	new_cmd_line->line = line;
	if (!command->cmd_line)
		command->cmd_line = new_cmd_line;
	else
		ft_dlstinsert(command->cmd_line->transport.left, \
					&new_cmd_line->transport, \
					&command->cmd_line->transport);
	command->count_cmd_lines += 1;
	return (new_cmd_line);
}
