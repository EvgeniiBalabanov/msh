/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:15:14 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 09:30:46 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_func_clear(t_dlist *content)
{
	ft_dlstclear(&content, \
		(void (*)(void *))ft_parse_element_destructor);
}

void	ft_parse_command_destructor(t_parse_command *command)
{
	if (command)
	{
		ft_dlstclear(&command->dlist_argums, \
			(void (*)(void *))ft_func_clear);
	}
}
