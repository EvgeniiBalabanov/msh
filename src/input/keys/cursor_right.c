/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 01:08:04 by telron            #+#    #+#             */
/*   Updated: 2021/06/09 00:17:52 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inp_keys_cursor_right(t_shell *config)
{
	size_t	count_symbol;
	size_t	now_length;

	count_symbol = ft_inp_get_mode_digit(config, 1);
	ft_inp_cursor_sync(config);
	now_length = ft_inp_cmd_line_get(config)->line->length;
	if (ft_inp_command_get(config)->xx_cursor + count_symbol > now_length)
		ft_inp_command_get(config)->xx_cursor = now_length;
	else
		ft_inp_command_get(config)->xx_cursor += count_symbol;
}
