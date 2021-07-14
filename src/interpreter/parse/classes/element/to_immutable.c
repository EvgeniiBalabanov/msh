/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_immutable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 17:55:45 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 09:37:29 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_init_func_parent(t_parse_element *parent)
{
	parent->checker = ft_parse_immutable_checker;
	parent->destructor = ft_parse_immutable_destructor;
	parent->run = ft_parse_immutable_run;
}

void	ft_parse_element_to_immutable(t_parse_element *element)
{
	t_line	*line;

	line = 0;
	if (element->type == SEPARATOR_CODE)
		line = element->content.separator.line;
	else if (element->type == STRING_CODE)
		line = element->content.separator.line;
	if (line)
	{
		element->type = IMMUTABLE_CODE;
		element->content.immutable.line = line;
		ft_init_func_parent(element);
	}
}
