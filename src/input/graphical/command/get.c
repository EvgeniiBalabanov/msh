/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 08:37:42 by telron            #+#    #+#             */
/*   Updated: 2021/06/10 11:32:28 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

inline t_command\
	*ft_inp_command_get(\
			t_shell *config)
{
	if (config->view.mode & MODE_CHOICE)
		return (&config->view.mode_choice.choice);
	if (config->view.mode & MODE_NOTE)
		return (&config->view.mode_note.note);
	if (config->view.mode & MODE_BUFFER)
		return (&config->view.mode_buffer.clipboard);
	return (config->view.command);
}
