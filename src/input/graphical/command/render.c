/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 09:05:00 by telron            #+#    #+#             */
/*   Updated: 2021/06/25 05:28:25 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_need_set_middle(\
						t_command *command, \
						size_t counter, \
						size_t add_counter, \
						t_line *line)
{
	return ((counter <= command->xx_cursor \
					&& command->xx_cursor < counter + add_counter) || \
					(line->length < command->xx_cursor));
}

static size_t	ft_get_add_counter(\
							t_shell *config, \
							size_t counter)
{
	size_t		add_counter;
	t_command	*command;

	command = ft_inp_command_get(config);
	add_counter = config->view.saved_winsize.ws_col;
	if (!counter)
		add_counter -= command->len_prefix;
	return (add_counter);
}

t_dlist	*ft_create_and_add_line(\
					t_shell *config, \
					size_t counters[3], \
					t_dlist **result, \
					t_line *line)
{
	t_output_line	*output_line;
	t_dlist			*new;

	output_line = ft_inp_output_line_new(\
				line, counters[2], counters[0], counters[0] + counters[1]);
	if (!output_line)
		ft_exit(config);
	new = ft_dlstadd_right_content(result, output_line);
	if (!new)
	{
		free(output_line);
		ft_exit(config);
	}
	return (new);
}

void	ft_if_is_cursor_line(\
					t_shell *config, \
					t_dlist *dlist, \
					t_dlist *new, \
					size_t counters[3])
{
	t_command		*command;
	t_line			*line;

	command = ft_inp_command_get(config);
	line = ((t_cmd_line *)dlist->content)->line;
	if (&command->cmd_line->transport == dlist)
	{
		((t_output_line *)new->content)->is_cursor_line = 1;
		if (ft_need_set_middle(command, counters[0], counters[1], line))
			config->view.draw.middle = new;
	}
}

void	ft_inp_command_render(t_shell *config)
{
	t_dlist			*dlist;
	t_dlist			*result;
	size_t			counters[3];
	t_dlist			*new;

	result = 0;
	counters[2] = 1;
	config->view.draw.middle = 0;
	dlist = ft_dlstleft(&ft_inp_command_get(config)->cmd_line->transport);
	while (dlist)
	{
		counters[0] = 0;
		while (counters[0] <= ((t_cmd_line *)dlist->content)->line->length)
		{
			counters[1] = ft_get_add_counter(config, counters[0]);
			new = ft_create_and_add_line(config, counters, &result, \
				((t_cmd_line *)dlist->content)->line);
			ft_if_is_cursor_line(config, dlist, new, counters);
			counters[0] += counters[1];
		}
		counters[2]++;
		dlist = dlist->right;
	}
}
