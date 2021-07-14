/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   note_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 10:51:49 by telron            #+#    #+#             */
/*   Updated: 2021/06/10 12:24:51 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_note_make(t_shell *config)
{
	t_command	*command;

	command = &config->view.mode_note.note;
	if (command->cmd_line)
	{
		ft_dlstiter_all_right(&command->cmd_line->transport, \
			(void (*)(void *))ft_inp_cmd_line_delone);
		command->cmd_line = 0;
	}
	ft_inp_cmd_line_new(command);
	return (0);
}

static void	ft_note_print(t_shell *config, int fd)
{
	t_cmd_line	*note_line;

	note_line = (t_cmd_line *)ft_dlstleft(\
		&config->view.mode_note.note.cmd_line->transport);
	while (note_line)
	{
		if (config->view.mode_note.note.cmd_line != note_line)
		{
			write(fd, note_line->line->string, note_line->line->length);
			if (note_line->transport.right)
				write(fd, "\n", 1);
		}
		note_line = (t_cmd_line *)note_line->transport.right;
	}
}

int	ft_note_start(t_shell *config, t_line *stop_world)
{
	int	save_mode;
	int	fd[2];

	save_mode = config->view.mode;
	config->view.mode = MODE_NOTE;
	config->view.mode |= MODE_INSERT;
	config->view.mode_note.stop_word = stop_world;
	ft_note_make(config);
	ft_input(config);
	config->view.mode = save_mode;
	pipe(fd);
	ft_note_print(config, fd[1]);
	close(fd[1]);
	return (fd[0]);
}
