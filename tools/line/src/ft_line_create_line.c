/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_create_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 03:27:48 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 19:14:50 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

t_line	*ft_line_create_line(t_line *line)
{
	t_line	*result;

	result = ft_line_new(line->allocated);
	if (result)
	{
		ft_strcpy(result->string, line->string);
		result->length = line->length;
		result->allocated = line->allocated;
	}
	return (result);
}
