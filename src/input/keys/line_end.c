/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 10:55:53 by telron            #+#    #+#             */
/*   Updated: 2021/06/08 10:15:33 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inp_keys_line_end(t_shell *config)
{
	ft_inp_command_get(config)->xx_cursor = \
		ft_inp_cmd_line_get(config)->line->length;
}
