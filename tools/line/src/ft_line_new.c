/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 23:17:11 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 19:29:16 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

t_line	*ft_line_new(size_t init_size)
{
	t_line	*result;

	result = (t_line *)malloc(sizeof(t_line));
	if (result)
	{
		result->string = (char *)malloc(init_size);
		if (!result->string)
		{
			free(result);
			return ((t_line *)0);
		}
		result->allocated = init_size;
		result->length = 0;
	}
	return (result);
}
