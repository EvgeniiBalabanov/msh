/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 12:10:34 by telron            #+#    #+#             */
/*   Updated: 2021/06/25 03:10:47 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_buffer_insert(t_shell *config, char char_buff)
{
	ft_inp_view_clean(&config->view);
	if (char_buff == '\033')
		ft_inp_keys_mode_to_normal(config);
	else if (char_buff == '\n')
		ft_inp_keys_classic_enter(config);
	else if (char_buff == '\t')
		ft_inp_keys_tab_prompt(config);
	else if (char_buff == '\003')
		ft_inp_keys_cursor_down_or_nl(config);
	else if (char_buff == '\004')
		ft_inp_keys_control_d(config);
	else if (char_buff == 127)
		ft_inp_keys_delete(config);
	else if (char_buff && ft_isascii(char_buff))
		ft_inp_keys_any_key(config, char_buff);
	ft_inp_view_render(config);
}
