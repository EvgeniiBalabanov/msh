/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:47:48 by telron            #+#    #+#             */
/*   Updated: 2021/06/22 01:59:06 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parse_element	*ft_parse_build(t_shell *config, t_line *line)
{
	t_parse_element	*result;
	t_dlist			*tokens;

	result = 0;
	tokens = 0;
	tokens = ft_parse_build_tokenize(config, line);
	if (tokens)
	{
		result = ft_parse_build_sequence(config, ft_dlstleft(tokens));
		if (result)
		{
			ft_dlstclear(&tokens, \
				(void (*)(void *))ft_parse_element_destructor);
			return (result);
		}
	}
	ft_dlstclear(&tokens, (void (*)(void *))ft_parse_element_destructor);
	return ((t_parse_element *)0);
}
