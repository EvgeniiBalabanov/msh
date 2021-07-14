/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:42:37 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 19:04:59 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ORIGINAL:
** 		#include <string.h>
**
** 		int		memcmp(const void *s1, const void *s2, size_t n);
** FUNCTION NAME:
** 		ft_memcmp
** INPUT PARAMS:
** 		mem_first	- адрес первого участка памяти
** 		mem_second	- адрес второго участка памяти
** 		size		- количество байт для сравнения
** INFO:
** 		Сравнивает 2 участка пямяти mem_first и mem_second
** 		на протяжении size байт
** RETURN:
** 		Разница в первом найденном байтовом различии.
*/

int	ft_memcmp(const void *mem_first, const void *mem_second, size_t size)
{
	unsigned char	*uc_first;
	unsigned char	*uc_second;
	size_t			counter;

	uc_first = (unsigned char *)mem_first;
	uc_second = (unsigned char *)mem_second;
	counter = 0;
	while (counter < size)
	{
		if (uc_first[counter] != uc_second[counter])
			return (uc_first[counter] - uc_second[counter]);
		counter++;
	}
	return (0);
}
