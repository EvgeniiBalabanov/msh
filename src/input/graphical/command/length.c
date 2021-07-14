/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:01:23 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 12:43:38 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_command_length(t_command *command)
{
	t_dlist		*dlst_line;
	size_t		result;

	result = 0;
	if (command->cmd_line)
	{
		dlst_line = ft_dlstleft(&command->cmd_line->transport);
		while (dlst_line)
		{
			result += ((t_cmd_line *)dlst_line->content)->line->length;
			dlst_line = dlst_line->right;
		}
	}
	return (result);
}
