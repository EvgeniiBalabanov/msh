/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:33:36 by telron            #+#    #+#             */
/*   Updated: 2021/06/29 13:49:58 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_parse_element	*ft_error_handler(\
									t_shell *config, \
									t_parse_element *element, \
									t_line *line, \
									int type)
{
	ft_line_del(line);
	ft_parse_element_destructor(element);
	if (type == 1)
	{
		ft_error_print(config, "ft_parse_build_variable", "malloc", "line");
		config->exit_code = 12;
	}
	else if (type == 2)
	{
		ft_error_print(config, "ft_parse_build_variable", "malloc", "line add");
		config->exit_code = 12;
	}
	else if (type == 3)
	{
		ft_error_print(config, "ft_parse_build_variable", "malloc", "element");
		config->exit_code = 12;
	}
	return (0);
}

t_parse_element	*ft_parse_build_variable(\
							t_shell *config, \
							char **str, \
							t_dlist **dlist)
{
	t_line			*line;
	t_parse_element	*element;

	element = 0;
	line = ft_line_create_str("");
	if (!line)
		return (ft_error_handler(config, element, line, 1));
	while (ft_isalnum(**str) || \
		(!line->length && (**str == '$' || **str == '?')))
	{
		if (!ft_line_add_chr(line, **str))
			return (ft_error_handler(config, element, line, 2));
		if (ft_strchr("$?", *(*str)++))
			break ;
	}
	if (line->length)
		element = ft_parse_variable_create(line);
	else if (!ft_line_add_chr(line, '$'))
		return (ft_error_handler(config, element, line, 2));
	else
		element = ft_parse_immutable_create(line);
	if (!element || !ft_dlstadd_right_content(dlist, element))
		return (ft_error_handler(config, element, line, 3));
	return (element);
}
