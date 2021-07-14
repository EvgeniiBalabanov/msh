/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_line_or_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:33:48 by telron            #+#    #+#             */
/*   Updated: 2021/06/09 00:18:54 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inp_keys_to_line_or_end(t_shell *config)
{
	t_command	*command;
	t_dlist		*dlist;

	if (ft_inp_get_mode_digit(config, 0))
		ft_inp_keys_to_line_or_home(config);
	else
	{
		command = ft_inp_command_get(config);
		dlist = ft_dlstright(&ft_inp_cmd_line_get(config)->transport);
		command->cmd_line = dlist->content;
		ft_inp_keys_line_home(config);
	}
}
