/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_add_sub_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:12:20 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 19:29:02 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

static int	ft_line_new_capacity(t_line *destination, \
					char **for_free, \
					char **dest_string, \
					size_t dest_new_length)
{
	if (dest_new_length + 1 > destination->allocated)
	{
		*dest_string = (char *)malloc(\
				ft_line_get_count_byte_allocate(dest_new_length + 1));
		if (!*dest_string)
			return (-1);
		destination->allocated = dest_new_length + 1;
		ft_memcpy(*dest_string, destination->string, destination->length);
		*for_free = destination->string;
	}
	else
		*dest_string = destination->string;
	return (0);
}

t_line	*ft_line_add_sub_line(\
					t_line *destination, \
					t_line *sub_line, \
					size_t start_index, \
					size_t stop_index)
{
	size_t	copy_length;
	size_t	dest_new_length;
	char	*dest_string;
	char	*for_free;

	if (sub_line->length < stop_index)
		stop_index = sub_line->length;
	if (start_index >= stop_index)
		return (destination);
	copy_length = stop_index - start_index;
	dest_new_length = destination->length + copy_length;
	for_free = 0;
	ft_line_new_capacity(destination, &for_free, &dest_string, dest_new_length);
	ft_memcpy(dest_string + destination->length, \
		sub_line->string + start_index, copy_length);
	destination->string = dest_string;
	destination->string[dest_new_length] = '\0';
	destination->length = dest_new_length;
	free(for_free);
	return (destination);
}
