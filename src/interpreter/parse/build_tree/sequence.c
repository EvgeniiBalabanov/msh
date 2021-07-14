/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:33:39 by telron            #+#    #+#             */
/*   Updated: 2021/06/25 05:10:44 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_get_mode(t_parse_element *element)
{
	const char	*seps[] = {"&&", "||", ";", "\n", 0};
	size_t		counter;

	counter = 0;
	while (seps[counter])
	{
		if (ft_parse_separator_is(element, seps[counter++]))
			return (counter);
	}
	return (0);
}

static t_parse_element	*ft_garbage_collector(t_dlist *dlist)
{
	ft_dlstclear(&dlist, (void (*)(void *))ft_parse_element_destructor);
	return (0);
}

static int	ft_create_item_mod(\
						t_shell *config, \
						t_dlist **elem_sequence, \
						t_parse_element	**result, \
						int mode)
{
	t_parse_element	*elem_after_pipe;

	if (*result)
		return (0);
	elem_after_pipe = ft_parse_build_pipe(config, *elem_sequence);
	ft_dlstclear(elem_sequence, (void (*)(void *))ft_parse_element_destructor);
	if (!elem_after_pipe)
		return (-1);
	if (mode == 1)
		*result = ft_parse_and_create(elem_after_pipe);
	else if (mode == 2)
		*result = ft_parse_or_create(elem_after_pipe);
	else
		*result = elem_after_pipe;
	if (!*result)
		ft_parse_element_destructor(elem_after_pipe);
	return (0);
}

static t_parse_element	*ft_parse_part(\
									t_shell *config, \
									t_dlist **tokens, \
									int *mode)
{
	t_dlist			*elem_sequence;
	int				new_mode;
	t_parse_element	*result;

	elem_sequence = 0;
	result = 0;
	while (*tokens && !result)
	{
		new_mode = ft_get_mode((*tokens)->content);
		if (!new_mode)
		{
			if (!ft_dlstadd_right_content(&elem_sequence, (*tokens)->content))
				return (ft_garbage_collector(elem_sequence));
			(*tokens)->content = 0;
		}
		else if (ft_create_item_mod(config, &elem_sequence, &result, *mode))
			return (ft_garbage_collector(elem_sequence));
		(*tokens) = (*tokens)->right;
	}
	if (ft_create_item_mod(config, &elem_sequence, &result, *mode))
		return (ft_garbage_collector(elem_sequence));
	*mode = new_mode;
	return (result);
}

t_parse_element	*ft_parse_build_sequence(t_shell *config, t_dlist *tokens)
{
	t_parse_element	*result;
	t_parse_element	*elem_seq;
	t_dlist			*dlist_sequence;
	int				mode;

	mode = 0;
	result = 0;
	dlist_sequence = 0;
	while (tokens)
	{
		elem_seq = ft_parse_part(config, &tokens, &mode);
		if ((tokens || dlist_sequence) && elem_seq)
		{
			if (!ft_dlstadd_right_content(&dlist_sequence, elem_seq))
				return (ft_garbage_collector(dlist_sequence));
			if (!result)
				result = ft_parse_sequence_create(dlist_sequence);
		}
		else
			result = elem_seq;
		if (!result)
			return (ft_garbage_collector(dlist_sequence));
	}
	return (result);
}
