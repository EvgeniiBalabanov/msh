/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_cut_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 07:46:42 by telron            #+#    #+#             */
/*   Updated: 2021/01/22 07:48:43 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

t_line	*ft_line_cut_index(t_line *line, size_t index)
{
	if (index < line->length)
	{
		line->string[index] = '\0';
		line->length = index;
	}
	return (line);
}
