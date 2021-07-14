/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 20:43:07 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 12:36:16 by telron           ###   ########.fr       */
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
		ft_error_print(config, "ft_build_separator", "malloc", "line");
		config->exit_code = 12;
	}
	else if (type == 2)
	{
		ft_error_print(config, "ft_build_separator", "malloc", "line add");
		config->exit_code = 12;
	}
	else if (type == 3)
	{
		ft_error_print(config, "ft_build_separator", "malloc", "element");
		config->exit_code = 12;
	}
	return (0);
}

t_parse_element	*ft_build_separator(\
							t_shell *config, \
							char **str, \
							t_dlist **dlist, \
							size_t count)
{
	t_line			*line;
	t_parse_element	*element;
	size_t			counter;

	element = 0;
	counter = 0;
	line = ft_line_create_str("");
	if (!line)
		return (ft_error_handler(config, element, line, 1));
	while (counter < count)
	{
		if (!ft_line_add_chr(line, (*str)[counter++]))
			return (ft_error_handler(config, element, line, 2));
	}
	element = ft_parse_separator_create(line);
	if (!element || !ft_dlstadd_right_content(dlist, element))
		return (ft_error_handler(config, element, line, 3));
	(*str) += count;
	return (element);
}
