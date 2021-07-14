/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:49:05 by telron            #+#    #+#             */
/*   Updated: 2021/06/25 03:38:37 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_choice_make(t_shell *config, t_dlist *dlist)
{
	t_command	*command;

	command = &config->view.mode_choice.choice;
	if (command->cmd_line)
	{
		ft_dlstiter_all_right(&command->cmd_line->transport, \
			(void (*)(void *))ft_inp_cmd_line_delone);
		command->cmd_line = 0;
	}
	while (dlist)
	{
		ft_inp_cmd_line_new(command);
		if (command->cmd_line->transport.right)
			command->cmd_line = \
				(t_cmd_line *)command->cmd_line->transport.right->content;
		ft_line_cpy_line(\
			command->cmd_line->line, \
			(t_line *)dlist->content);
		dlist = dlist->right;
	}
	return (0);
}

static void	ft_init_mode_choice(t_shell *config, char char_buffer)
{
	t_mode_choice	*mode_choice;

	mode_choice = &config->view.mode_choice;
	mode_choice->input_buffer[mode_choice->buffer_length] = char_buffer;
	mode_choice->buffer_length++;
}

static int	ft_reload_view(t_shell *config)
{
	config->view.mode_choice.buffer_length = 0;
	config->view.mode_choice.digit_for_normal = 0;
	return (0);
}

static void	ft_choice_run(\
						t_shell *config, \
						char char_buffer, \
						void *set_keys[][2])
{
	size_t	counter;
	void	**set;

	ft_init_mode_choice(config, char_buffer);
	counter = 0;
	while (*set_keys[counter])
	{
		set = set_keys[counter++];
		if (!ft_strncmp(config->view.mode_choice.input_buffer, set[0], \
							config->view.mode_choice.buffer_length))
		{
			if (config->view.mode_choice.buffer_length == ft_strlen(set[0]))
			{
				((void (*)(t_shell *))set[1])(config);
				ft_reload_view(config);
			}
			return ;
		}
	}
	ft_reload_view(config);
}

int	ft_choice(t_shell *config, char char_buffer)
{
	size_t			*digit_ptr;
	static void		*set_keys[][2] = {{"\033[B", ft_inp_keys_cursor_down}, \
	{"\033[A", ft_inp_keys_cursor_up}, {"gg", ft_inp_keys_to_line_or_home}, \
	{"G", ft_inp_keys_to_line_or_end}, \
	{0, 0}};

	ft_inp_view_clean(&config->view);
	if (char_buffer == '\n')
		return (1);
	if (ft_isdigit(char_buffer))
	{
		digit_ptr = ft_inp_get_mode_digit_ptr(config);
		*digit_ptr *= 10;
		*digit_ptr += char_buffer - '0';
		ft_inp_view_render(config);
		return (0);
	}
	ft_choice_run(config, char_buffer, set_keys);
	ft_inp_view_render(config);
	return (0);
}
