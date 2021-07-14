/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 00:23:50 by telron            #+#    #+#             */
/*   Updated: 2021/06/29 07:15:12 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCTS_H
# define MINISHELL_STRUCTS_H

# include "minishell_includes.h"

typedef struct s_cmd_line
{
	t_dlist				transport;
	t_line				*line;
}						t_cmd_line;

typedef struct s_command
{
	t_dlist				transport;
	size_t				count_cmd_lines;
	size_t				index_up_line;
	size_t				index_down_line;
	size_t				xx_cursor;
	size_t				len_prefix;
	t_cmd_line			*cmd_line;
}						t_command;

typedef struct s_mode_choice
{
	char				input_buffer[32];
	size_t				buffer_length;
	size_t				digit_for_normal;
	t_command			choice;
}						t_mode_choice;

typedef struct s_mode_buffer
{
	char				input_buffer[32];
	size_t				buffer_length;
	size_t				digit_for_normal;
	t_command			clipboard;
}						t_mode_buffer;

typedef struct s_mode_normal
{
	char				input_buffer[32];
	size_t				buffer_length;
	size_t				digit_for_normal;
}						t_mode_normal;

typedef struct s_mode_note
{
	char				input_buffer[32];
	size_t				buffer_length;
	size_t				digit_for_normal;
	t_command			note;
	t_line				*stop_word;
}						t_mode_note;

typedef struct s_output_line
{
	t_line				*line;
	char				is_first_line;
	char				is_cursor_line;
	size_t				index;
	size_t				start;
	size_t				stop;
}						t_output_line;

typedef struct s_draw
{
	size_t				lines;
	t_dlist				*begin;
	t_dlist				*middle;
	size_t				columns;
	size_t				index_sugnature;
	size_t				height;
	int					yy_global;
	int					xx_global;
	int					yy_real;
	int					xx_real;
}						t_draw;

typedef struct s_view
{
	char				mode;
	char				canvas;
	t_mode_normal		mode_normal;
	t_mode_choice		mode_choice;
	t_mode_note			mode_note;
	t_mode_buffer		mode_buffer;
	t_command			*command;
	t_line				*signature;
	size_t				count_command;
	size_t				index_command;
	t_draw				draw;
	struct winsize		saved_winsize;
	int					fd_dev_tty;
}						t_view;

typedef struct s_shell
{
	const char			**env_origin;
	t_dict				*environment;
	t_view				view;
	int					exit_code;
	struct termios		term_saved_attributes;
	char				is_child;
}						t_shell;

typedef struct s_dir
{
	DIR					*dir;
	struct dirent		*entry;
}						t_dir;

#endif
