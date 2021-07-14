/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_mem_realloc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 08:53:54 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 19:22:42 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

t_line	*ft_line_mem_realloc(t_line *line, size_t length)
{
	char	*for_free;
	char	*alloc_memmory;
	size_t	new_size_allocated;

	new_size_allocated = line->allocated;
	if (new_size_allocated < length + 1)
		new_size_allocated = ft_line_get_count_byte_allocate(length + 1);
	if (new_size_allocated != line->allocated)
	{
		for_free = line->string;
		alloc_memmory = (char *)malloc(new_size_allocated);
		if (!alloc_memmory)
			return ((t_line *)0);
		line->string = alloc_memmory;
		line->allocated = new_size_allocated;
		if (for_free)
			ft_strcpy(line->string, for_free);
		else
			ft_strcpy(line->string, "");
		free(for_free);
	}
	return (line);
}
