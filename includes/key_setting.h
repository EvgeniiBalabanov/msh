/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_setting.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 03:16:59 by telron            #+#    #+#             */
/*   Updated: 2021/06/10 12:07:47 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_SETTING_H
# define KEY_SETTING_H

# include "minishell_structs.h"

void		ft_inp_keys_any_key(t_shell *config, char chr);
void		ft_inp_keys_mode_to_insert(t_shell *config);
void		ft_inp_keys_mode_to_normal(t_shell *config);
void		ft_inp_keys_delete(t_shell *config);
void		ft_inp_keys_cursor_left(t_shell *config);
void		ft_inp_keys_cursor_left_to_insert(t_shell *config);
void		ft_inp_keys_cursor_right(t_shell *config);
void		ft_inp_keys_cursor_right_to_insert(t_shell *config);
void		ft_inp_keys_cursor_up(t_shell *config);
void		ft_inp_keys_cursor_up_to_insert(t_shell *config);
void		ft_inp_keys_cursor_down(t_shell *config);
void		ft_inp_keys_cursor_down_to_insert(t_shell *config);
void		ft_inp_keys_cursor_down_or_nl(t_shell *config);
void		ft_inp_keys_cursor_down_or_nl_to_insert(t_shell *config);
void		ft_inp_keys_enter(t_shell *config);
void		ft_inp_keys_enter_line(t_shell *config);
void		ft_inp_keys_insert_enter(t_shell *config);
void		ft_inp_keys_command_up(t_shell *config);
void		ft_inp_keys_command_down(t_shell *config);
void		ft_inp_keys_classic_enter(t_shell *config);
void		ft_inp_keys_skip_word_right(t_shell *config);
void		ft_inp_keys_skip_word_left(t_shell *config);
void		ft_inp_keys_line_home(t_shell *config);
void		ft_inp_keys_line_end(t_shell *config);
void		ft_inp_keys_to_line_or_home(t_shell *config);
void		ft_inp_keys_to_line_or_end(t_shell *config);
void		ft_inp_keys_new_line_up(t_shell *config);
void		ft_inp_keys_new_line_down(t_shell *config);
void		ft_inp_keys_line_add_clipboard(t_shell *config);
void		ft_inp_keys_clipboard_paste_up(t_shell *config);
void		ft_inp_keys_clipboard_paste_down(t_shell *config);
void		ft_inp_keys_clipboard_paste_up(t_shell *config);
void		ft_inp_keys_clipboard_clear(t_shell *config);
void		ft_inp_keys_line_to_clipboard(t_shell *config);
void		ft_inp_keys_line_delete(t_shell *config);
void		ft_inp_keys_tab_prompt(t_shell *config);
void		ft_inp_keys_command_new(t_shell *config);
void		ft_inp_keys_to_command_or_home(t_shell *config);
void		ft_inp_keys_command_delete(t_shell *config);
void		ft_inp_keys_control_d(t_shell *config);
void		ft_inp_keys_view_clipbord(t_shell *config);
void		ft_inp_keys_view_main_command(t_shell *config);

# define MODE_INSERT			0b000001
# define MODE_NORMAL			0b000010
# define MODE_SCRIPT			0b000100
# define MODE_CHOICE			0b001000
# define MODE_NOTE				0b010000
# define MODE_BUFFER			0b100000

# define MODE_DEFAULT			MODE_INSERT

#endif
