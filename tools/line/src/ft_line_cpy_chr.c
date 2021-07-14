/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_cpy_chr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 02:07:04 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 19:31:50 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

t_line	*ft_line_cpy_chr(t_line *destination, char sourse)
{
	size_t	new_size_allocated;
	char	*buf;
	size_t	len;

	len = (sourse != 0);
	new_size_allocated = destination->allocated;
	if (new_size_allocated < 1 + len)
		new_size_allocated = 16;
	if (destination->allocated != new_size_allocated)
	{
		buf = (char *)malloc(new_size_allocated);
		if (!buf)
			return ((t_line *)0);
		free(destination->string);
		destination->string = buf;
		destination->allocated = new_size_allocated;
	}
	destination->length = len;
	destination->string[len] = '\0';
	destination->string[0] = sourse;
	return (destination);
}
