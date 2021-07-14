/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:15:01 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 10:04:24 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_init_func_parent(t_parse_element *parent)
{
	parent->checker = ft_parse_immutable_checker;
	parent->destructor = ft_parse_immutable_destructor;
	parent->run = ft_parse_immutable_run;
}

t_parse_element	*ft_parse_immutable_create(t_line *line)
{
	t_parse_element	*new_element;

	new_element = ft_calloc(1, sizeof(t_parse_element));
	if (new_element)
	{
		new_element->type = IMMUTABLE_CODE;
		new_element->content.immutable.line = line;
		ft_init_func_parent(new_element);
	}
	return (new_element);
}
