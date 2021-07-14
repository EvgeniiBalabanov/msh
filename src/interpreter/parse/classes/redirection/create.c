/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:15:01 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 09:39:34 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_init_func_parent(t_parse_element *parent)
{
	parent->checker = ft_parse_redirection_checker;
	parent->destructor = ft_parse_redirection_destructor;
	parent->run = ft_parse_redirection_run;
}

t_parse_element	*ft_parse_redirection_create(\
							t_parse_element *element, \
							t_dlist *name_file, \
							int type)
{
	t_parse_element	*new_element;

	new_element = ft_calloc(1, sizeof(t_parse_element));
	if (new_element)
	{
		new_element->type = REDIRECTION_CODE;
		new_element->content.redirection.element = element;
		new_element->content.redirection.name_file = name_file;
		new_element->content.redirection.type = type;
		ft_init_func_parent(new_element);
	}
	return (new_element);
}
