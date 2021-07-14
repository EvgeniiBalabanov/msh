/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   note_normal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:53:41 by telron            #+#    #+#             */
/*   Updated: 2021/06/25 02:31:02 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_note_normal_input_char(\
						t_shell *config, \
						char char_buffer, \
						void *set_keys[][2])
{
	size_t			counter;
	void			**set;
	t_mode_note		*mode_note;

	mode_note = &config->view.mode_note;
	mode_note->input_buffer[mode_note->buffer_length] = char_buffer;
	mode_note->buffer_length++;
	counter = 0;
	while (set_keys[counter][0])
	{
		set = set_keys[counter++];
		if (!ft_strncmp(mode_note->input_buffer, set[0], \
							mode_note->buffer_length))
		{
			if (mode_note->buffer_length != ft_strlen(set[0]))
				return ;
			((void (*)(t_shell *))set[1])(config);
			break ;
		}
	}
	mode_note->buffer_length = 0;
	mode_note->digit_for_normal = 0;
}

void	ft_note_normal_run(\
					t_shell *config, \
					char char_buffer, \
					void *set_keys[][2])
{
	ft_inp_view_clean(&config->view);
	if (ft_isdigit(char_buffer))
	{
		config->view.mode_note.digit_for_normal *= 10;
		config->view.mode_note.digit_for_normal += char_buffer - '0';
	}
	else
		ft_note_normal_input_char(config, char_buffer, set_keys);
	ft_inp_view_render(config);
}

void	ft_note_normal(t_shell *config, char char_buffer)
{
	static void		*set_keys[][2] = {{"p", ft_inp_keys_clipboard_paste_down}, \
	{"[B", ft_inp_keys_cursor_down_or_nl_to_insert}, \
	{"\033[1;2C", ft_inp_keys_skip_word_right}, {"\177", ft_inp_keys_delete}, \
	{"[C", ft_inp_keys_cursor_right_to_insert}, {"k", ft_inp_keys_cursor_up}, \
	{"\033[1;2D", ft_inp_keys_skip_word_left}, {"[F", ft_inp_keys_line_end}, \
	{"\033[B", ft_inp_keys_cursor_down_or_nl}, {"[H", ft_inp_keys_line_home}, \
	{"[D", ft_inp_keys_cursor_left_to_insert}, {"h", ft_inp_keys_cursor_left}, \
	{"[A", ft_inp_keys_cursor_up_to_insert}, {"O", ft_inp_keys_new_line_up}, \
	{"ya", ft_inp_keys_line_add_clipboard}, {"l", ft_inp_keys_cursor_right}, \
	{"[1;2C", ft_inp_keys_skip_word_right}, {"dd", ft_inp_keys_line_delete}, \
	{"yy", ft_inp_keys_line_to_clipboard}, {"\004", ft_inp_keys_control_d}, \
	{"[1;2D", ft_inp_keys_skip_word_left}, {"\033[F", ft_inp_keys_line_end}, \
	{"P", ft_inp_keys_clipboard_paste_up}, {"o", ft_inp_keys_new_line_down}, \
	{"\033[C", ft_inp_keys_cursor_right}, {"i", ft_inp_keys_mode_to_insert}, \
	{"j", ft_inp_keys_cursor_down_or_nl}, {"\033[A", ft_inp_keys_cursor_up}, \
	{"yd", ft_inp_keys_clipboard_clear}, {"b", ft_inp_keys_skip_word_left}, \
	{"gg", ft_inp_keys_to_line_or_home}, {"\033[H", ft_inp_keys_line_home}, \
	{"\033[D", ft_inp_keys_cursor_left}, {"\n", ft_inp_keys_classic_enter}, \
	{"e", ft_inp_keys_skip_word_right}, {"G", ft_inp_keys_to_line_or_end}, \
	{0, 0}};

	ft_note_normal_run(config, char_buffer, set_keys);
}
