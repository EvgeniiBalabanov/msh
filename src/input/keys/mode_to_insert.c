/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode_to_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 05:43:32 by telron            #+#    #+#             */
/*   Updated: 2021/06/10 11:36:11 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inp_keys_mode_to_insert(t_shell *config)
{
	config->view.mode &= ~MODE_NORMAL;
	config->view.mode |= MODE_INSERT;
}
