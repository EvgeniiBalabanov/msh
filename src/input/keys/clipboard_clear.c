/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipboard_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 19:41:57 by telron            #+#    #+#             */
/*   Updated: 2021/06/10 11:17:55 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inp_keys_clipboard_clear(t_shell *config)
{
	if (config->view.mode_buffer.clipboard.cmd_line)
		ft_dlstiter_all_right(\
			&config->view.mode_buffer.clipboard.cmd_line->transport, \
			(void (*)(void *))ft_inp_cmd_line_delone);
	ft_bzero(&config->view.mode_buffer.clipboard, sizeof(t_command));
}
