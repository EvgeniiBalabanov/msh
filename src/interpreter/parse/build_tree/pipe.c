/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:33:44 by telron            #+#    #+#             */
/*   Updated: 2021/06/21 02:59:53 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_parse_element	*ft_error_handler(\
									t_shell *config, \
									t_dlist **command, \
									t_dlist **buffer, \
									int type)
{
	ft_dlstclear(buffer, (void (*)(void *))ft_parse_element_destructor);
	ft_dlstclear(command, (void (*)(void *))ft_parse_element_destructor);
	if (type == 1)
	{
		ft_error_print(config, "ft_parse_build_pipe", \
			"syntax error near unexpected token", "|");
		config->exit_code = 258;
	}
	else if (type == 2)
	{
		ft_error_print(config, "ft_parse_build_pipe", "malloc", "command add");
		config->exit_code = 12;
	}
	else if (type == 3)
	{
		ft_error_print(config, "ft_parse_build_pipe", "malloc", "buffer add");
		config->exit_code = 12;
	}
	return (0);
}

static int	ft_command_is_valid(\
						t_dlist *command, \
						t_dlist *buffer, \
						char is_end)
{
	t_dlist			*dlist;
	t_parse_element	*element;

	dlist = ft_dlstleft(buffer);
	while (dlist)
	{
		element = (t_parse_element *)dlist->content;
		if (element->type != SEPARATOR_CODE)
			return (1);
		dlist = dlist->right;
	}
	return (!command && is_end);
}

static t_parse_element	*ft_create_pipe_tree(t_dlist *command)
{
	t_parse_element	*result;
	t_dlist			*for_free;

	for_free = command;
	result = command->content;
	command = command->right;
	while (command)
	{
		result = ft_parse_pipe_create(result, command->content);
		command = command->right;
	}
	ft_dlstclear(&for_free, 0);
	return (result);
}

static t_parse_element	*ft_command_add_buffer(\
									t_shell *config, \
									t_dlist **command, \
									t_dlist **buffer, \
									char is_end)
{
	t_parse_element	*element;

	element = 0;
	if (!ft_command_is_valid(*command, *buffer, is_end))
		return (ft_error_handler(config, command, buffer, 1));
	element = ft_parse_build_tilda(config, *buffer);
	if (!element)
		return (ft_error_handler(config, command, buffer, 0));
	if (!ft_dlstadd_right_content(command, element))
		return (ft_error_handler(config, command, buffer, 2));
	ft_dlstclear(buffer, (void (*)(void *))ft_parse_element_destructor);
	return (element);
}

t_parse_element	*ft_parse_build_pipe(t_shell *config, t_dlist *tokens)
{
	t_dlist			*command;
	t_dlist			*buffer;
	t_parse_element	*element;

	command = 0;
	buffer = 0;
	while (tokens)
	{
		element = (t_parse_element *)tokens->content;
		if (element->type != SEPARATOR_CODE || \
			ft_strcmp(element->content.separator.line->string, "|"))
		{
			if (!ft_dlstadd_right_content(&buffer, element))
				return (ft_error_handler(config, &command, &buffer, 3));
			tokens->content = 0;
		}
		else if (!ft_command_add_buffer(config, &command, &buffer, 0))
			return (0);
		tokens = tokens->right;
	}
	if (ft_command_add_buffer(config, &command, &buffer, 1))
		return (ft_create_pipe_tree(command));
	return (0);
}
