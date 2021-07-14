/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_add_clipboard.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:00:05 by telron            #+#    #+#             */
/*   Updated: 2021/06/10 11:17:55 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inp_keys_line_add_clipboard(t_shell *config)
{
	size_t		count_line;
	t_command	*source_command;

	source_command = ft_inp_command_get(config);
	count_line = ft_inp_get_mode_digit(config, 1);
	ft_inp_command_com2com_copy(\
		&config->view.mode_buffer.clipboard, \
		source_command, count_line);
}
