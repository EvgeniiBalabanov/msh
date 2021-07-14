/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:15:01 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 10:01:43 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_init_func_parent(t_parse_element *parent)
{
	parent->checker = ft_parse_pipe_checker;
	parent->destructor = ft_parse_pipe_destructor;
	parent->run = ft_parse_pipe_run;
}

t_parse_element	*ft_parse_pipe_create(\
							t_parse_element *left, \
							t_parse_element *right)
{
	t_parse_element	*new_element;

	new_element = ft_calloc(1, sizeof(t_parse_element));
	if (new_element)
	{
		new_element->type = PIPE_CODE;
		new_element->content.pipe.left = left;
		new_element->content.pipe.right = right;
		ft_init_func_parent(new_element);
	}
	return (new_element);
}
