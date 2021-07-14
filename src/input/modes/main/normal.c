/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 05:05:26 by telron            #+#    #+#             */
/*   Updated: 2021/06/25 02:30:39 by telron           ###   ########.fr       */
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
	t_mode_normal	*mode_normal;

	mode_normal = &config->view.mode_normal;
	mode_normal->input_buffer[mode_normal->buffer_length] = char_buffer;
	mode_normal->buffer_length++;
	counter = 0;
	while (*set_keys[counter])
	{
		set = set_keys[counter++];
		if (!ft_strncmp(mode_normal->input_buffer, set[0], \
												mode_normal->buffer_length))
		{
			if (mode_normal->buffer_length != ft_strlen(set[0]))
				return ;
			((void (*)(t_shell *))set[1])(config);
			break ;
		}
	}
	mode_normal->buffer_length = 0;
	mode_normal->digit_for_normal = 0;
}

static void	ft_normal_run(\
						t_shell *config, \
						char char_buffer, \
						void *set_keys[][2])
{
	ft_inp_view_clean(&config->view);
	if (ft_isdigit(char_buffer))
	{
		config->view.mode_normal.digit_for_normal *= 10;
		config->view.mode_normal.digit_for_normal += char_buffer - '0';
	}
	else
		ft_normal_input_char(config, char_buffer, set_keys);
	ft_inp_view_render(config);
}

void	ft_normal(t_shell *config, char char_buffer)
{
	static void	*set_keys[][2] = {{"\177", ft_inp_keys_delete}, \
	{"[B", ft_inp_keys_cursor_down_or_nl_to_insert}, \
	{"[C", ft_inp_keys_cursor_right_to_insert}, {"k", ft_inp_keys_cursor_up}, \
	{"[D", ft_inp_keys_cursor_left_to_insert}, {"[H", ft_inp_keys_line_home}, \
	{"\e[1;2C", ft_inp_keys_skip_word_right}, {"[F", ft_inp_keys_line_end}, \
	{"\e[1;2D", ft_inp_keys_skip_word_left}, {"h", ft_inp_keys_cursor_left}, \
	{"[A", ft_inp_keys_cursor_up_to_insert}, {"z", ft_inp_keys_command_up}, \
	{"p", ft_inp_keys_clipboard_paste_down}, {"O", ft_inp_keys_new_line_up}, \
	{"\e[B", ft_inp_keys_cursor_down_or_nl}, {"\033[F", ft_inp_keys_line_end}, \
	{"cc", ft_inp_keys_to_command_or_home}, {"G", ft_inp_keys_to_line_or_end}, \
	{"[1;2C", ft_inp_keys_skip_word_right}, {"cb", ft_inp_keys_view_clipbord}, \
	{"ya", ft_inp_keys_line_add_clipboard}, {"\n", ft_inp_keys_enter_line}, \
	{"[1;2D", ft_inp_keys_skip_word_left}, {"\004", ft_inp_keys_control_d}, \
	{"yy", ft_inp_keys_line_to_clipboard}, {"cn", ft_inp_keys_command_new}, \
	{"P", ft_inp_keys_clipboard_paste_up}, {"dd", ft_inp_keys_line_delete}, \
	{"\033[C", ft_inp_keys_cursor_right}, {"x", ft_inp_keys_command_down}, \
	{"\033[D", ft_inp_keys_cursor_left}, {"o", ft_inp_keys_new_line_down}, \
	{"gg", ft_inp_keys_to_line_or_home}, {"i", ft_inp_keys_mode_to_insert}, \
	{"\\\n", ft_inp_keys_classic_enter}, {"b", ft_inp_keys_skip_word_left}, \
	{"yd", ft_inp_keys_clipboard_clear}, {"\033[H", ft_inp_keys_line_home}, \
	{"e", ft_inp_keys_skip_word_right}, {"\033[A", ft_inp_keys_cursor_up}, \
	{"cd", ft_inp_keys_command_delete}, {"j", ft_inp_keys_cursor_down_or_nl}, \
	{"a\n", ft_inp_keys_enter}, {"l", ft_inp_keys_cursor_right}, {0, 0}};

	ft_normal_run(config, char_buffer, set_keys);
}
