/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_init_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:45:56 by aberry            #+#    #+#             */
/*   Updated: 2021/06/25 05:27:44 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		\
	ft_inp_init_draw(\
			t_shell *config)
{
	config->view.draw.lines = (config->view.saved_winsize.ws_row - 1) / 2;
}
