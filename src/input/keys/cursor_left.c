/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 00:54:55 by telron            #+#    #+#             */
/*   Updated: 2021/06/09 00:16:21 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inp_keys_cursor_left(t_shell *config)
{
	size_t		count_symbol;
	t_command	*command;

	command = ft_inp_command_get(config);
	count_symbol = ft_inp_get_mode_digit(config, 1);
	ft_inp_cursor_sync(config);
	if (command->xx_cursor < count_symbol)
		command->xx_cursor = 0;
	else
		command->xx_cursor -= count_symbol;
}
