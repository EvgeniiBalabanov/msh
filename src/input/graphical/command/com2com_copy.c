/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com2com_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:02:33 by aberry            #+#    #+#             */
/*   Updated: 2021/06/08 10:15:33 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_inp_command_com2com_copy(\
					t_command *destination, \
					t_command *source, \
					size_t count_line)
{
	size_t		copy_line;
	t_cmd_line	*source_cmd_line;

	copy_line = 0;
	source_cmd_line = source->cmd_line;
	while (source_cmd_line && count_line--)
	{
		ft_inp_cmd_line_new(destination);
		if (destination->cmd_line->transport.right)
			destination->cmd_line = \
				(t_cmd_line *)destination->cmd_line->transport.right->content;
		ft_line_cpy_line(destination->cmd_line->line, source_cmd_line->line);
		if (source_cmd_line->transport.right)
			source_cmd_line = source_cmd_line->transport.right->content;
		else
			source_cmd_line = 0;
		copy_line++;
	}
	return (copy_line);
}

size_t	ft_inp_command_com2com_copy_up(\
					t_command *destination, \
					t_command *source, \
					size_t count_line)
{
	size_t		copy_line;
	t_cmd_line	*source_cmd_line;

	copy_line = 0;
	source_cmd_line = source->cmd_line;
	while (source_cmd_line && count_line--)
	{
		ft_inp_cmd_line_new_up(destination);
		if (destination->cmd_line->transport.left)
			destination->cmd_line = \
				(t_cmd_line *)destination->cmd_line->transport.left->content;
		ft_line_cpy_line(\
			destination->cmd_line->line, \
			source_cmd_line->line);
		if (source_cmd_line->transport.left)
			source_cmd_line = source_cmd_line->transport.left->content;
		else
			source_cmd_line = 0;
		copy_line++;
	}
	return (copy_line);
}
