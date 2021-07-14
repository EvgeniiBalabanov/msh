/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_add_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 08:52:30 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 19:25:45 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

t_line	*ft_line_add_line(t_line *line, t_line *tail)
{
	if (!ft_line_mem_realloc(line, line->length + tail->length))
		return ((t_line *)0);
	ft_strcpy(line->string + line->length, tail->string);
	line->length += tail->length;
	return (line);
}
