/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_enter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:20:52 by telron            #+#    #+#             */
/*   Updated: 2021/06/10 12:01:21 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inp_keys_insert_enter(t_shell *config)
{
	ft_inp_keys_enter_line(config);
	ft_inp_keys_cursor_down_or_nl(config);
	ft_inp_keys_line_end(config);
}
