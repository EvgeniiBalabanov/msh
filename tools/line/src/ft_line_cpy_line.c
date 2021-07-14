/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_cpy_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 04:16:15 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 19:37:26 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

t_line	*ft_line_cpy_line(t_line *destination, t_line *sourse)
{
	if (!ft_line_mem_up_to(destination, sourse->length))
		return ((t_line *)0);
	ft_strcpy(destination->string, sourse->string);
	destination->length = sourse->length;
	return (destination);
}
