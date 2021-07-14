/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_line_or_home.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:33:50 by telron            #+#    #+#             */
/*   Updated: 2021/06/10 12:01:21 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inp_keys_to_line_or_home(t_shell *config)
{
	t_command	*command;
	size_t		*digit_ptr;

	command = ft_inp_command_get(config);
	command->cmd_line = \
			(t_cmd_line *)ft_dlstleft(&command->cmd_line->transport)->content;
	digit_ptr = ft_inp_get_mode_digit_ptr(config);
	if (*digit_ptr > 1)
	{
		(*digit_ptr)--;
		ft_inp_keys_cursor_down_or_nl(config);
	}
	ft_inp_keys_line_home(config);
}
