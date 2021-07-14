/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   note.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 00:58:24 by telron            #+#    #+#             */
/*   Updated: 2021/06/25 02:30:53 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_note(t_shell *config, char char_buffer)
{
	ft_inp_view_clean(&config->view);
	if (char_buffer == '\033')
		ft_inp_keys_mode_to_normal(config);
	else if (char_buffer == '\n')
	{
		if (!ft_strcmp(config->view.mode_note.stop_word->string, \
			ft_inp_cmd_line_get(config)->line->string))
			return (1);
		ft_inp_keys_classic_enter(config);
	}
	else if (char_buffer == '\003')
		ft_inp_keys_cursor_down_or_nl(config);
	else if (char_buffer == '\004')
		ft_inp_keys_control_d(config);
	else if (char_buffer == 127)
		ft_inp_keys_delete(config);
	else if (char_buffer && ft_isprint(char_buffer))
		ft_inp_keys_any_key(config, char_buffer);
	ft_inp_view_render(config);
	return (0);
}
