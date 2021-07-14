/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_del_chr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 03:18:11 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 19:14:43 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

void	ft_line_del_chr(t_line *line, size_t index)
{
	if (line->length > index)
	{
		ft_memmove(line->string + index, \
					line->string + index + 1, \
					line->length-- - index + 1);
	}
}
