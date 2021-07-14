/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:26:27 by telron            #+#    #+#             */
/*   Updated: 2021/06/29 12:26:52 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inp_keys_control_d(t_shell *config)
{
	t_cmd_line	*cmd_line;

	cmd_line = ft_inp_cmd_line_get(config);
	if (!cmd_line->line->length)
	{
		if (config->view.mode != MODE_SCRIPT)
			ft_putendl_fd("exit", 1);
		ft_exit(config);
	}
}
