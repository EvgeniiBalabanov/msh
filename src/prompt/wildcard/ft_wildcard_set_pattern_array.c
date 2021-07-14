/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcard_set_pattern_array.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:11:42 by aberry            #+#    #+#             */
/*   Updated: 2021/06/07 13:59:16 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ft_wildcard_get_index(t_line *pattern)
{
	char		*offset;
	size_t		index;

	offset = ft_strchr(pattern->string, '/');
	if (offset)
		index = offset - pattern->string;
	else
		index = pattern->length;
	return (index);
}

char	**ft_wildcard_set_pattern_array(\
					t_line *pattern, \
					t_line **pattern_tmp)
{
	size_t		index;
	size_t		i;
	char		**pattern_array;

	index = ft_wildcard_get_index(pattern);
	pattern_array = 0;
	*pattern_tmp = ft_line_sub_line(pattern, 0, index);
	if (!*pattern_tmp)
		return (pattern_array);
	i = 0;
	while (i < index)
	{
		ft_line_del_chr(pattern, 0);
		i++;
	}
	pattern_array = ft_split((*pattern_tmp)->string, '*');
	return (pattern_array);
}
