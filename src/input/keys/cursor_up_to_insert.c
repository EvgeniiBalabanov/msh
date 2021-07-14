/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_up_to_insert.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 07:14:30 by telron            #+#    #+#             */
/*   Updated: 2021/06/08 10:15:33 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inp_keys_cursor_up_to_insert(t_shell *config)
{
	ft_inp_keys_cursor_up(config);
	ft_inp_keys_mode_to_insert(config);
}
