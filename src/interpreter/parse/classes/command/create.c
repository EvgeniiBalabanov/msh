/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:15:01 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 09:31:00 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_init_func_parent(t_parse_element *new_element)
{
	new_element->checker = ft_parse_command_checker;
	new_element->destructor = ft_parse_command_destructor;
	new_element->run = ft_parse_command_run;
}

t_parse_element	*ft_parse_command_create(t_dlist *dlist_argums)
{
	t_parse_element	*new_element;

	new_element = ft_calloc(1, sizeof(t_parse_element));
	if (new_element)
	{
		new_element->type = COMMAND_CODE;
		new_element->content.command.dlist_argums = dlist_argums;
		ft_init_func_parent(new_element);
	}
	return (new_element);
}
