/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipboard_paste_up.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:14:12 by aberry            #+#    #+#             */
/*   Updated: 2021/06/10 11:17:15 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** @function ft_inp_keys_clipboard_paste_up
** Вставляет строку из буфера выше на одну строчку
** @рaram Основная структура минишелла
** @author Aaron Berry
** @version 1.0
*/

void	ft_inp_keys_clipboard_paste_up(t_shell *config)
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
			ft_inp_command_com2com_copy_up(destination_command, \
																clipboard, -1);
	}
}
