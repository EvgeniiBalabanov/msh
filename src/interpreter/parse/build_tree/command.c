/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:33:56 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 01:12:27 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_dlist	*ft_add_argums(t_dlist **argums, t_dlist **tokens)
{
	t_dlist		*argum;

	argum = 0;
	while (*tokens)
	{
		if (((t_parse_element *)(*tokens)->content)->type != SEPARATOR_CODE)
		{
			ft_dlstadd_right_content(&argum, (*tokens)->content);
			(*tokens)->content = 0;
		}
		else
			break ;
		*tokens = (*tokens)->right;
	}
	ft_dlstadd_right_content(argums, argum);
	return (argum);
}

t_parse_element	*ft_parse_build_command(t_dlist *tokens)
{
	t_dlist		*dlist_argums;
	t_dlist		*for_free;

	for_free = tokens;
	dlist_argums = 0;
	while (tokens)
	{
		if (((t_parse_element *)tokens->content)->type != SEPARATOR_CODE)
			ft_add_argums(&dlist_argums, &tokens);
		if (tokens)
			tokens = tokens->right;
	}
	ft_dlstclear(&for_free, (void (*)(void *))ft_parse_element_destructor);
	return (ft_parse_command_create(dlist_argums));
}
