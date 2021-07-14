/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_sub_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:13:04 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 19:25:28 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

t_line	*ft_line_sub_line(t_line *line, size_t start_index, \
							size_t stop_index)
{
	t_line	*result;
	size_t	length;

	if (stop_index > line->length)
		stop_index = line->length;
	if (stop_index < start_index)
		length = 0;
	else
		length = stop_index - start_index;
	result = ft_line_new(0);
	if (result)
	{
		if (!ft_line_mem_up_to(result, length))
		{
			ft_line_del(result);
			return (0);
		}
		result->length = length;
		result->string[length] = '\0';
		while (length--)
			result->string[length] = line->string[start_index + length];
	}
	return (result);
}
