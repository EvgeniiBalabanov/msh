/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 22:11:46 by telron            #+#    #+#             */
/*   Updated: 2021/06/11 01:05:45 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_line	*ft_build_lines(\
							t_command *command, \
							size_t count_lines, \
							char from_the_first_line)
{
	t_dlist		*dlist;
	t_cmd_line	*insert_cmd_line;
	t_line		*line;

	dlist = &command->cmd_line->transport;
	if (from_the_first_line)
		dlist = ft_dlstleft(dlist);
	line = ft_line_create_str("");
	if (!line)
		return (0);
	while (line && dlist && count_lines--)
	{
		insert_cmd_line = (t_cmd_line *)dlist->content;
		if (!insert_cmd_line)
			break ;
		if (!ft_line_add_line(line, insert_cmd_line->line) || \
			(dlist->right && !ft_line_add_chr(line, '\n')))
		{
			ft_line_del(line);
			return (0);
		}
		dlist = dlist->right;
	}
	return (line);
}

void	ft_run(t_shell *config, t_parse_element *element)
{
	t_stream	stream;

	stream.exit_code = 0;
	stream.descriptors.std_in = 0;
	stream.descriptors.std_out = 1;
	stream.descriptors.std_err = 2;
	ft_parse_element_run(config, &stream, element);
	config->exit_code = stream.exit_code;
}

int	ft_run_cmd_lines(\
				t_shell *config, \
				size_t count_lines, \
				char from_the_first_line)
{
	t_line			*line;
	t_parse_element	*element;
	t_command		*command;

	command = ft_inp_command_get(config);
	if (!command)
	{
		config->exit_code = 66;
		return (66);
	}
	line = ft_build_lines(command, count_lines, from_the_first_line);
	if (!line)
	{
		config->exit_code = 12;
		return (12);
	}
	element = ft_parse_build(config, line);
	ft_line_del(line);
	if (element)
	{
		ft_run(config, element);
		ft_parse_element_destructor(element);
	}
	return (config->exit_code);
}
