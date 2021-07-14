/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipboard_paste_down.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:55:23 by telron            #+#    #+#             */
/*   Updated: 2021/06/10 11:17:15 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inp_keys_clipboard_paste_down(t_shell *config)
{
	t_command	*destination_command;
	t_command	*clipboard;

	destination_command = ft_inp_command_get(config);
	clipboard = &config->view.mode_buffer.clipboard;
	if (clipboard->cmd_line)
	{
		clipboard->cmd_line = \
					ft_dlstleft(&clipboard->cmd_line->transport)->content;
		if (clipboard->cmd_line)
			ft_inp_command_com2com_copy(destination_command, clipboard, -1);
	}
}
