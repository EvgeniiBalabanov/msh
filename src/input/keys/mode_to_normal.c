/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode_to_normal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 05:44:41 by telron            #+#    #+#             */
/*   Updated: 2021/06/10 11:38:07 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inp_keys_mode_to_normal(t_shell *config)
{
	config->view.mode &= ~MODE_INSERT;
	config->view.mode |= MODE_NORMAL;
}
