/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 21:05:50 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 10:39:57 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_parse_element	*ft_error_handler(\
									t_shell *config, \
									t_parse_element *element, \
									int type)
{
	ft_parse_element_destructor(element);
	if (type == 1)
	{
		ft_error_print(config, "ft_parse_build_string", "malloc", "element");
		config->exit_code = 12;
	}
	else if (type == 2)
	{
		ft_error_print(config, "ft_parse_build_string", "malloc", "dlist");
		config->exit_code = 12;
	}
	else if (type == 3)
	{
		ft_error_print(config, "ft_parse_build_string", "malloc", "line");
		config->exit_code = 12;
	}
	return (0);
}

t_parse_element	*ft_parse_build_string(\
							t_shell *config, \
							t_line **line, \
							t_dlist **dlist)
{
	t_parse_element	*element;
	t_line			*new_line;

	element = 0;
	if ((*line)->length)
	{
		element = ft_parse_string_create(*line);
		if (!element)
			return (ft_error_handler(config, element, 1));
		if (!ft_dlstadd_right_content(dlist, element))
			return (ft_error_handler(config, element, 2));
		new_line = ft_line_create_str("");
		if (!new_line)
			return (ft_error_handler(config, element, 3));
		*line = new_line;
		return (element);
	}
	return ((t_parse_element *) -1);
}
