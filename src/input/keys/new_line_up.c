/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_line_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 06:17:16 by telron            #+#    #+#             */
/*   Updated: 2021/06/08 10:15:33 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inp_keys_new_line_up(t_shell *config)
{
	t_command	*command;

	command = ft_inp_command_get(config);
	if (ft_inp_cmd_line_new_up(command))
		command->cmd_line = command->cmd_line->transport.left->content;
	ft_inp_keys_mode_to_insert(config);
}
