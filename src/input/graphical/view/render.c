/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 21:32:28 by telron            #+#    #+#             */
/*   Updated: 2021/07/01 16:01:26 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_print_line(\
						t_shell *config, \
						size_t global_index, \
						t_output_line *output_line)
{
	ft_to_line(config, global_index);
	if (output_line->is_first_line)
		ft_print_index(config, output_line->index);
	if (output_line->is_cursor_line)
		write(config->view.fd_dev_tty, "\033[4;37m", 7);
	write(config->view.fd_dev_tty, \
		output_line->line->string + output_line->start, \
		ft_min(output_line->stop - output_line->start, \
			ft_strlen(output_line->line->string + output_line->start)));
	if (output_line->is_cursor_line)
		write(config->view.fd_dev_tty, "\033[m", 3);
	write(config->view.fd_dev_tty, "\r", 1);
}

static void	ft_print_signature(\
						t_shell *config, \
						size_t global_index, \
						t_line *signature)
{
	ft_to_line(config, global_index);
	write(config->view.fd_dev_tty, signature->string, signature->length);
	write(config->view.fd_dev_tty, "\r", 1);
}

static void	ft_print_lines(t_shell *config, size_t index)
{
	t_output_line	*output_line;
	size_t			counter;
	t_dlist			*dlist;

	counter = 0;
	dlist = config->view.draw.begin;
	while (dlist && counter++ < config->view.draw.lines)
	{
		output_line = dlist->content;
		ft_print_line(config, index++, output_line);
		dlist = dlist->right;
	}
}

static void	ft_inp_view_render_setup(t_shell *config)
{
	config->view.draw.yy_global = config->view.saved_winsize.ws_row;
	config->view.draw.xx_global = 0;
	if (config->view.draw.height < config->view.draw.lines)
	{
		ft_put_n(&config->view, \
			config->view.draw.lines - config->view.draw.height);
		config->view.draw.height = config->view.draw.lines;
	}
	ft_inp_sugnature_render(config);
	ft_print_signature(config, config->view.draw.index_sugnature, \
													config->view.signature);
	ft_print_lines(config, config->view.draw.index_sugnature + 1);
	ft_up(&config->view, config->view.draw.yy_real);
	ft_dlstclear(&(config->view.draw.middle), \
								(void (*)(void *))ft_inp_output_line_delete);
	ft_right(&config->view, config->view.draw.xx_real);
}

void	ft_inp_view_render(t_shell *config)
{
	t_command		*command;

	command = ft_inp_command_get(config);
	ft_inp_command_reload_len_prefix(command);
	ft_inp_command_render(config);
	config->view.draw.xx_real = ft_min(command->xx_cursor, \
								ft_inp_cmd_line_get(config)->line->length);
	config->view.draw.xx_real += command->len_prefix;
	config->view.draw.xx_real %= (int)config->view.saved_winsize.ws_col;
	ft_inp_init_draw(config);
	ft_get_begin(config);
	config->view.draw.index_sugnature = config->view.saved_winsize.ws_row - \
													config->view.draw.lines;
	ft_inp_view_render_setup(config);
}
