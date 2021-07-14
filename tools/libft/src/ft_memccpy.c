/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:01:48 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 19:03:14 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ORIGINAL:
** 		#include <string.h>
**
** 		void	*
** 		memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
** FUNCTION NAME:
** 		ft_memccpy
** INPUT PARAMS:
** 		destination	- адрес по которому будут записаны данные
** 		source		- source, адрес из которого будут браться данные
** 		value		- до какого значения байта будет производиться копирование
** 		size		- максимальное количество байт,
** 						которые могут быть скопированы
** INFO:
** 		Копирует данные из source в destination
** 		до value символа, но не более size байт
** 		Та же функция memcpy, только с остановкой на value символе
** EXAMPLE:
** 		IN:
** 			(destination = (address 100), source = (address 500),
** 													value = 0x33, size = 5)
** 		COPY:
** 													value
** 													 V
** 			(address 100) ->|0x05	0x70	0x00	0x33	0x77	0x88...|
** 							|		<-		size = 5	->		|
** 			(address 500) ->|0x01	0x02	0x03	0x04	0x05	0x06...|
** 		OUT:
** 			(address 500) ->|0x05	0x70	0x00	0x33	0x05	0x06...|
** 		RETURN:
** 														|	0x05	0x06...|
*/

void	*ft_memccpy(void *destination, \
					const void *source, \
					int value, \
					size_t size)
{
	unsigned char		*dst;
	const unsigned char	*src;
	size_t				counter;

	counter = 0;
	dst = (unsigned char *)destination;
	src = (const unsigned char *)source;
	while (counter < size)
	{
		dst[counter] = src[counter];
		if (dst[counter++] == (unsigned char)value)
			return (dst + counter);
	}
	return ((void *)0);
}
