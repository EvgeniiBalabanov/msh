/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_get_count_byte_allocate.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:29:52 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 19:14:07 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

size_t	ft_line_get_count_byte_allocate(size_t need_byte)
{
	size_t	counter;

	counter = 16;
	while (need_byte > counter)
		counter *= 2;
	return (counter);
}
