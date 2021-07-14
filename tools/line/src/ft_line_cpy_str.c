/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_cpy_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 23:36:15 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 19:37:28 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

t_line	*ft_line_cpy_str(t_line *destination, const char *sourse)
{
	size_t	len;

	len = ft_strlen(sourse);
	if (ft_line_mem_up_to(destination, len))
	{
		destination->length = len;
		destination->string[len] = '\0';
		while (len--)
			destination->string[len] = sourse[len];
		return (destination);
	}
	return ((t_line *)0);
}
