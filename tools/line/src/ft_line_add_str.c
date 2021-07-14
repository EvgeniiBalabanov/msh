/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_add_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 07:57:54 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 19:29:19 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

t_line	*ft_line_add_str(t_line *line, const char *tail)
{
	size_t	len;

	len = ft_strlen(tail);
	if (!ft_line_mem_realloc(line, line->length + len))
		return ((t_line *)0);
	ft_strcpy(line->string + line->length, tail);
	line->length += len;
	return (line);
}
