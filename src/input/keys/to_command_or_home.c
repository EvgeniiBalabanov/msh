/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_command_or_home.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:24:53 by telron            #+#    #+#             */
/*   Updated: 2021/06/09 00:21:56 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inp_keys_to_command_or_home(t_shell *config)
{
	t_view	*view;
	size_t	*digit_ptr;

	view = &config->view;
	view->command = ft_dlstleft(&view->command->transport)->content;
	view->index_command = 1;
	digit_ptr = ft_inp_get_mode_digit_ptr(config);
	while (view->command->transport.right && *digit_ptr > 1)
	{
		(*digit_ptr)--;
		view->command = view->command->transport.right->content;
		view->index_command += 1;
	}
}
