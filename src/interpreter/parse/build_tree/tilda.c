/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilda.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 02:21:12 by telron            #+#    #+#             */
/*   Updated: 2021/06/21 03:56:11 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_is_type(t_dlist *dlist, int code)
{
	t_parse_element	*element;

	element = dlist->content;
	return (element->type == code);
}

static int	ft_has_slash(t_dlist *dlist)
{
	t_parse_element	*element;

	element = dlist->content;
	return (ft_is_type(dlist, STRING_CODE) && \
		element->content.string.line->string[0] == '/');
}

t_parse_element	*ft_parse_build_tilda(t_shell *config, t_dlist *tokens)
{
	t_dlist			*dlist;
	t_parse_element	*element;

	dlist = ft_dlstleft(tokens);
	while (dlist)
	{
		element = dlist->content;
		if (ft_parse_separator_is(element, "~"))
		{
			if ((!dlist->left || ft_is_type(dlist->left, SEPARATOR_CODE)) && \
			((!dlist->right || ft_is_type(dlist->right, SEPARATOR_CODE)) || \
			ft_has_slash(dlist->right)))
				dlist->content = ft_parse_tilda_create();
			else
				dlist->content = \
					ft_parse_string_create(ft_line_create_str("~"));
			ft_parse_element_destructor(element);
		}
		dlist = dlist->right;
	}
	return (ft_parse_build_redirection(config, tokens));
}
