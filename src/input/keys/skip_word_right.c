/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_word_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 09:56:55 by telron            #+#    #+#             */
/*   Updated: 2021/06/08 10:15:33 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inp_keys_skip_word_right(t_shell *config)
{
	t_command	*command;
	t_line		*line;

	ft_inp_cursor_sync(config);
	line = ft_inp_cmd_line_get(config)->line;
	command = ft_inp_command_get(config);
	if (line->string[command->xx_cursor])
	{
		command->xx_cursor++;
		while (line->string[command->xx_cursor])
		{
			if (ft_isalnum(line->string[command->xx_cursor - 1]) && \
				!ft_isalnum(line->string[command->xx_cursor]))
				break ;
			command->xx_cursor++;
		}
	}
}
