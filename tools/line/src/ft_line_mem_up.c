/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_mem_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 23:29:23 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 19:29:37 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

t_line	*ft_line_mem_up(t_line *line, size_t size)
{
	char	*for_free;
	char	*alloc_memmory;
	size_t	len;

	if (size)
	{
		for_free = line->string;
		alloc_memmory = (char *)malloc(line->allocated + size);
		if (!alloc_memmory)
			return ((t_line *)0);
		line->string = alloc_memmory;
		line->allocated = line->allocated + size;
		len = line->length;
		line->string[len] = '\0';
		while (len--)
			line->string[len] = for_free[len];
		free(for_free);
	}
	return (line);
}
