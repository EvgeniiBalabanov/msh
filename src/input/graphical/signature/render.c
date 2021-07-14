/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 07:29:53 by telron            #+#    #+#             */
/*   Updated: 2021/06/10 11:34:18 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_add_signature_line(t_shell *config)
{
	t_command	*command;

	command = ft_inp_command_get(config);
	ft_line_add_str(config->view.signature, "LN ");
	ft_add_colon(config->view.signature);
	ft_line_add_str(config->view.signature, " [");
	ft_add_number(config->view.signature, command->index_up_line);
	ft_line_add_str(config->view.signature, "-");
	ft_add_number(config->view.signature, command->index_down_line);
	ft_line_add_str(config->view.signature, "/");
	ft_add_number(config->view.signature, command->count_cmd_lines);
	ft_line_add_str(config->view.signature, "] | ");
}

static void	ft_add_signature_cmd(t_shell *config)
{
	if (config->view.mode & ~MODE_NORMAL & ~MODE_INSERT)
		return ;
	ft_line_add_str(config->view.signature, "CMD ");
	ft_add_colon(config->view.signature);
	ft_line_add_str(config->view.signature, " [");
	ft_add_number(config->view.signature, config->view.index_command);
	ft_line_add_str(config->view.signature, "/");
	ft_add_number(config->view.signature, config->view.count_command);
	ft_line_add_str(config->view.signature, "] | ");
}

static void	ft_add_signature_mode(t_shell *config)
{
	if (config->view.mode & MODE_BUFFER)
		ft_line_add_str(config->view.signature, "BUFFER ");
	else if (config->view.mode & MODE_CHOICE)
		ft_line_add_str(config->view.signature, "CHOICE ");
	else if (config->view.mode & MODE_NOTE)
	{
		ft_line_add_str(config->view.signature, "NOTE[");
		ft_line_add_line(config->view.signature, \
			config->view.mode_note.stop_word);
		ft_line_add_str(config->view.signature, "] ");
	}
}

static void	ft_add_signature_insert_or_normal(t_shell *config)
{
	size_t	counter;
	size_t	buffer_length;
	char	*input_buffer;

	if (config->view.mode & MODE_INSERT)
		ft_line_add_str(config->view.signature, "INSERT");
	else if (config->view.mode & MODE_NORMAL || config->view.mode & MODE_CHOICE)
	{
		ft_line_add_str(config->view.signature, "NORMAL[");
		counter = ft_inp_get_mode_digit(config, 0);
		if (counter)
			ft_add_number(config->view.signature, counter);
		counter = 0;
		buffer_length = ft_get_len_hot_key(config);
		input_buffer = ft_get_str_hot_key(config);
		while (counter < buffer_length)
		{
			if (ft_isprint(input_buffer[counter]))
				ft_line_add_chr(config->view.signature, input_buffer[counter]);
			counter++;
		}
		ft_line_add_str(config->view.signature, "]");
	}
	ft_line_add_str(config->view.signature, " | ");
}

void	ft_inp_sugnature_render(t_shell *config)
{
	ft_line_del(config->view.signature);
	config->view.signature = ft_line_create_str("<| msh | ");
	ft_add_signature_line(config);
	ft_add_signature_cmd(config);
	ft_add_signature_mode(config);
	ft_add_signature_insert_or_normal(config);
	ft_add_pwd(config, config->view.signature);
	ft_line_add_str(config->view.signature, " |>");
}
