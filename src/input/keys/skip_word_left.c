/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_word_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 10:20:11 by telron            #+#    #+#             */
/*   Updated: 2021/06/08 10:15:33 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inp_keys_skip_word_left(t_shell *config)
{
	t_command	*command;
	t_line		*line;

	ft_inp_cursor_sync(config);
	line = ft_inp_cmd_line_get(config)->line;
	command = ft_inp_command_get(config);
	if (command->xx_cursor >= 1)
	{
		command->xx_cursor--;
		while (command->xx_cursor >= 1)
		{
			if (ft_isalnum(line->string[command->xx_cursor]) && \
				!ft_isalnum(line->string[command->xx_cursor - 1]))
				break ;
			command->xx_cursor--;
		}
	}
}
