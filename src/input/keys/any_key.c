/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 14:30:08 by telron            #+#    #+#             */
/*   Updated: 2021/06/08 10:09:15 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inp_keys_any_key(t_shell *config, const char chr)
{
	ft_inp_cursor_sync(config);
	ft_line_insert_chr(ft_inp_cmd_line_get(config)->line, \
		chr, ft_inp_command_get(config)->xx_cursor++);
}
