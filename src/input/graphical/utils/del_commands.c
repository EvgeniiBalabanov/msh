/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:41:59 by telron            #+#    #+#             */
/*   Updated: 2021/06/08 10:15:33 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_del_commands(t_shell *config)
{
	ft_dlstiter_all_right(&config->view.command->transport, \
		(void (*)(void *))ft_inp_command_delone);
}
