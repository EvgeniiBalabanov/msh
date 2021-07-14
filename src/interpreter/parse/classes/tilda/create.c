/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 02:48:46 by telron            #+#    #+#             */
/*   Updated: 2021/06/21 02:52:04 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_init_func_parent(t_parse_element *parent)
{
	parent->checker = ft_parse_string_checker;
	parent->destructor = ft_parse_string_destructor;
	parent->run = ft_parse_string_run;
}

t_parse_element	*ft_parse_tilda_create(void)
{
	t_parse_element	*new_element;

	new_element = ft_calloc(1, sizeof(t_parse_element));
	if (new_element)
	{
		new_element->type = TILDA_CODE;
		ft_init_func_parent(new_element);
	}
	return (new_element);
}
