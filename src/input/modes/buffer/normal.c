/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 05:05:26 by telron            #+#    #+#             */
/*   Updated: 2021/06/25 03:10:57 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_normal_input_char(\
						t_shell *config, \
						char char_buffer, \
						void *set_keys[][2])
{
	size_t			counter;
	void			**set;
	t_mode_buffer	*mode_buffer;

	mode_buffer = &config->view.mode_buffer;
	mode_buffer->input_buffer[mode_buffer->buffer_length] = char_buffer;
	mode_buffer->buffer_length++;
	counter = 0;
	while (*set_keys[counter])
	{
		set = set_keys[counter++];
		if (!ft_strncmp(mode_buffer->input_buffer, set[0], \
												mode_buffer->buffer_length))
		{
			if (mode_buffer->buffer_length != ft_strlen(set[0]))
				return ;
			((void (*)(t_shell *))set[1])(config);
			break ;
		}
	}
	mode_buffer->buffer_length = 0;
	mode_buffer->digit_for_normal = 0;
}

static void	ft_buffer_normal_run(\
						t_shell *config, \
						char char_buffer, \
						void *set_keys[][2])
{
	ft_inp_view_clean(&config->view);
	if (ft_isdigit(char_buffer))
	{
		config->view.mode_buffer.digit_for_normal *= 10;
		config->view.mode_buffer.digit_for_normal += char_buffer - '0';
	}
	else
		ft_normal_input_char(config, char_buffer, set_keys);
	ft_inp_view_render(config);
}

void	ft_buffer_normal(t_shell *config, char char_buffer)
{
	static void		*set_keys[][2] = {{"cm", ft_inp_keys_view_main_command}, \
	{"[B", ft_inp_keys_cursor_down_or_nl_to_insert}, \
	{"[C", ft_inp_keys_cursor_right_to_insert}, {"a\n", ft_inp_keys_enter}, \
	{"\033[1;2C", ft_inp_keys_skip_word_right}, {"\177", ft_inp_keys_delete}, \
	{"\033[1;2D", ft_inp_keys_skip_word_left}, {"[F", ft_inp_keys_line_end}, \
	{"[D", ft_inp_keys_cursor_left_to_insert}, {"[H", ft_inp_keys_line_home}, \
	{"[A", ft_inp_keys_cursor_up_to_insert}, {"z", ft_inp_keys_command_up}, \
	{"O", ft_inp_keys_new_line_up}, {"k", ft_inp_keys_cursor_up}, \
	{"j", ft_inp_keys_cursor_down_or_nl}, {"\n", ft_inp_keys_enter_line}, \
	{"[1;2C", ft_inp_keys_skip_word_right}, {"h", ft_inp_keys_cursor_left}, \
	{"[1;2D", ft_inp_keys_skip_word_left}, {"\004", ft_inp_keys_control_d}, \
	{"cn", ft_inp_keys_command_new}, {"dd", ft_inp_keys_line_delete}, \
	{"cm", ft_inp_keys_view_main_command}, {"l", ft_inp_keys_cursor_right}, \
	{"\033[C", ft_inp_keys_cursor_right}, {"x", ft_inp_keys_command_down}, \
	{"\033[D", ft_inp_keys_cursor_left}, {"o", ft_inp_keys_new_line_down}, \
	{"\033[B", ft_inp_keys_cursor_down_or_nl}, {"\033[F", ft_inp_keys_line_end}, \
	{"gg", ft_inp_keys_to_line_or_home}, {"i", ft_inp_keys_mode_to_insert}, \
	{"\\\n", ft_inp_keys_classic_enter}, {"b", ft_inp_keys_skip_word_left}, \
	{"\033[H", ft_inp_keys_line_home}, {"G", ft_inp_keys_to_line_or_end}, \
	{"e", ft_inp_keys_skip_word_right}, {"\033[A", ft_inp_keys_cursor_up}, \
	{"cd", ft_inp_keys_command_delete}, {0, 0}};

	ft_buffer_normal_run(config, char_buffer, set_keys);
}
