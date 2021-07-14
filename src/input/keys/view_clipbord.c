/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_clipbord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:28:37 by telron            #+#    #+#             */
/*   Updated: 2021/06/10 11:23:44 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inp_keys_view_clipbord(t_shell *config)
{
	if (config->view.mode_buffer.clipboard.count_cmd_lines || \
		ft_inp_cmd_line_new(&config->view.mode_buffer.clipboard))
	{
		config->view.mode = MODE_INSERT;
		config->view.mode |= MODE_BUFFER;
	}
}
