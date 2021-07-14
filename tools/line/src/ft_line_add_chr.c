/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_add_chr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 23:29:08 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 20:09:26 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

t_line	*ft_line_add_chr(t_line *line, char chr)
{
	if (!ft_line_mem_realloc(line, line->length + 1))
		return ((t_line *)0);
	line->string[line->length++] = chr;
	line->string[line->length] = 0;
	return (line);
}
