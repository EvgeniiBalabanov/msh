/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guard.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:32:17 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 14:59:47 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_parse_element	*ft_error_handler(\
									t_shell *config, \
									t_parse_element *element, \
									t_line *line, \
									int type)
{
	ft_parse_element_destructor(element);
	ft_line_del(line);
	if (type == 1)
	{
		ft_error_print(config, "ft_parse_build_guard", "malloc", "line");
		config->exit_code = 12;
	}
	else if (type == 2)
	{
		ft_error_print(config, "ft_parse_build_guard", "malloc", "element");
		config->exit_code = 12;
	}
	else if (type == 3)
	{
		ft_error_print(config, "ft_parse_build_guard", "malloc", "dlist");
		config->exit_code = 12;
	}
	else if (type == 4)
	{
		ft_error_print(config, "ft_parse_build_guard", \
					"syntax error near unexpected token", "\\");
		config->exit_code = 12;
	}
	return (0);
}

t_parse_element	*ft_parse_build_guard(\
							t_shell *config, \
							char **str, \
							t_dlist **dlist)
{
	t_parse_element	*element;
	t_line			*new_line;

	new_line = 0;
	element = 0;
	if (**str == '\n')
	{
		(*str)++;
		return ((t_parse_element *) -1);
	}
	else if (**str)
	{
		new_line = ft_line_create_chr(**str);
		if (!new_line)
			return (ft_error_handler(config, element, new_line, 1));
		element = ft_parse_immutable_create(new_line);
		if (!element)
			return (ft_error_handler(config, element, new_line, 2));
		if (!ft_dlstadd_right_content(dlist, element))
			return (ft_error_handler(config, element, new_line, 3));
		(*str)++;
		return (element);
	}
	return (ft_error_handler(config, element, new_line, 4));
}
