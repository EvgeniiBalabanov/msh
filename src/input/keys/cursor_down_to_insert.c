/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_down_to_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 12:05:29 by telron            #+#    #+#             */
/*   Updated: 2021/06/10 12:05:43 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inp_keys_cursor_down_to_insert(t_shell *config)
{
	ft_inp_keys_cursor_down(config);
	ft_inp_keys_mode_to_insert(config);
}
