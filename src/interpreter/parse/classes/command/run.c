/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:15:31 by telron            #+#    #+#             */
/*   Updated: 2021/06/21 04:04:02 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_line	*ft_variable(\
							t_shell *config, \
							t_line *destination, \
							t_line *source)
{
	char	*str_variable;

	str_variable = ft_env_var_get_by_user(config, source->string);
	if (str_variable)
		return (ft_line_add_str(destination, str_variable));
	return (destination);
}

static t_line	*ft_get_argum(t_shell *config, t_dlist *argum)
{
	t_line			*line;
	t_parse_element	*element;
	t_line			*not_error;

	line = ft_line_create_str("");
	not_error = line;
	while (argum && not_error)
	{
		element = argum->content;
		if (element->type == IMMUTABLE_CODE)
			not_error = ft_line_add_line(line, element->content.immutable.line);
		else if (element->type == STRING_CODE)
			not_error = ft_line_add_line(line, element->content.string.line);
		else if (element->type == VARIABLE_CODE)
			not_error = ft_variable(\
								config, line, element->content.variable.line);
		else if (element->type == TILDA_CODE)
			not_error = ft_line_add_str(\
								line, ft_env_var_get_by_system(config, "HOME"));
		argum = argum->right;
	}
	if (not_error)
		return (line);
	ft_line_del(line);
	return (0);
}

static t_dlist	*ft_to_argums(\
							t_shell *config, \
							t_dlist *argums)
{
	t_line	*line;
	t_dlist	*dlist_for_create_pp;
	t_dlist	*dlist_wildcard;
	t_dlist	*right;

	dlist_for_create_pp = 0;
	while (argums)
	{
		line = ft_get_argum(config, argums->content);
		dlist_wildcard = ft_parse_wildcard(line);
		if (!dlist_wildcard)
			ft_dlstadd_right_content(&dlist_for_create_pp, line);
		else
		{
			right = ft_dlstright(dlist_wildcard);
			ft_dlstrelation(ft_dlstright(dlist_for_create_pp), \
							ft_dlstleft(dlist_wildcard));
			dlist_for_create_pp = right;
			ft_line_del(line);
		}
		argums = argums->right;
	}
	return (ft_dlstleft(dlist_for_create_pp));
}

void	ft_parse_command_run(\
					t_shell *config, \
					t_stream *stream, \
					t_parse_command *command)
{
	t_dlist			*dlist_for_create_pp;
	t_dlist			*dlist;
	size_t			count;
	t_executable	executable;
	char			**argums;

	dlist_for_create_pp = ft_to_argums(config, command->dlist_argums);
	count = ft_dlstsize(dlist_for_create_pp);
	argums = ft_calloc(count + 1, sizeof(char *));
	count = 0;
	dlist = dlist_for_create_pp;
	while (dlist)
	{
		argums[count++] = ((t_line *)dlist->content)->string;
		dlist = dlist->right;
	}
	executable.argums = (const char **)argums;
	ft_memcpy(&executable.descriptors, &stream->descriptors, \
												sizeof(t_descriptors));
	stream->exit_code = ft_launch_executable(config, &executable);
	config->exit_code = stream->exit_code;
	free(executable.argums);
	ft_dlstclear(&dlist_for_create_pp, (void (*)(void *))ft_line_del);
}
