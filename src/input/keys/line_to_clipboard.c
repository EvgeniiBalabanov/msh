/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_clipboard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 19:52:09 by telron            #+#    #+#             */
/*   Updated: 2021/06/10 11:33:15 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inp_keys_line_to_clipboard(t_shell *config)
{
	if (config->view.mode & MODE_BUFFER)
		return ;
	ft_inp_keys_clipboard_clear(config);
	ft_inp_keys_line_add_clipboard(config);
}
