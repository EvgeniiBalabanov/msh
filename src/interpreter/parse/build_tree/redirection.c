/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:33:41 by telron            #+#    #+#             */
/*   Updated: 2021/06/21 02:58:10 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_parse_element	*ft_error_handler(\
									t_shell *config, \
									t_dlist **command_tokens, \
									int redirect_type, \
									int type)
{
	static const char	*redirections[] = {">>", ">", "<", "<<"};

	ft_dlstclear(command_tokens, (void (*)(void *))ft_parse_element_destructor);
	if (type == 1)
	{
		if (redirect_type == 4)
			ft_error_print(config, "ft_parse_build_redirection", \
			"invalid stop word constructor", redirections[redirect_type - 1]);
		else
			ft_error_print(config, "ft_parse_build_redirection", \
			"invalid filename constructor", redirections[redirect_type - 1]);
		config->exit_code = 258;
	}
	return (0);
}

static int	ft_is_redirection(t_parse_element *element)
{
	char	*string;

	if (element && element->type == SEPARATOR_CODE)
	{
		string = element->content.separator.line->string;
		if (!ft_strcmp(string, ">>"))
			return (1);
		else if (!ft_strcmp(string, ">"))
			return (2);
		else if (!ft_strcmp(string, "<"))
			return (3);
		else if (!ft_strcmp(string, "<<"))
			return (4);
	}
	return (0);
}

static t_dlist	*ft_build_filename(t_dlist **dlist)
{
	t_parse_element	*element;
	t_dlist			*file_name;

	while (*dlist && (*dlist)->content)
	{
		element = (t_parse_element *)(*dlist)->content;
		if (element->type != SEPARATOR_CODE || \
							element->content.separator.line->string[0] != ' ')
			break ;
		*dlist = (*dlist)->right;
	}
	file_name = 0;
	while (*dlist)
	{
		element = (t_parse_element *)(*dlist)->content;
		if ((element->type == SEPARATOR_CODE && \
			element->content.separator.line->string[0] == ' ') || \
			ft_is_redirection(element))
			break ;
		ft_dlstadd_right_content(&file_name, (*dlist)->content);
		(*dlist)->content = 0;
		*dlist = (*dlist)->right;
	}
	return (file_name);
}

t_parse_element	*ft_redirection(\
							t_shell *config, \
							t_dlist **command_tokens, \
							t_dlist *tokens, \
							int type)
{
	t_parse_element	*element;
	t_dlist			*dlist;
	t_dlist			*file_name;

	dlist = tokens;
	file_name = ft_build_filename(&dlist);
	if (!file_name)
		return (ft_error_handler(config, command_tokens, type, 1));
	while (dlist)
	{
		ft_dlstadd_right_content(command_tokens, dlist->content);
		dlist->content = 0;
		dlist = dlist->right;
	}
	element = ft_parse_redirection_create(\
		ft_parse_build_redirection(config, *command_tokens), file_name, type);
	ft_dlstclear(command_tokens, (void (*)(void *))ft_parse_element_destructor);
	return (element);
}

t_parse_element	*ft_parse_build_redirection(\
							t_shell *config, \
							t_dlist *tokens)
{
	t_dlist			*dlist;
	t_dlist			*command_tokens;
	t_parse_element	*element;
	int				type;

	dlist = tokens;
	command_tokens = 0;
	while (dlist)
	{
		element = dlist->content;
		type = ft_is_redirection(element);
		if (type)
		{
			dlist = dlist->right;
			return (ft_redirection(config, &command_tokens, dlist, type));
		}
		else
		{
			ft_dlstadd_right_content(&command_tokens, element);
			dlist->content = 0;
		}
		dlist = dlist->right;
	}
	return (ft_parse_build_command(command_tokens));
}
