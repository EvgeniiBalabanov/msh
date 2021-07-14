/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:55:51 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 19:03:44 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ORIGINAL:
** 		#include <string.h>
**
** 		void	*memcpy(void *restrict dst, const void *restrict src, size_t n);
** FUNCTION NAME:
** 		ft_memcpy
** INPUT PARAMS:
** 		dst		- desctination, адрес по которому будут записаны данные
** 		source	- source, адрес из которого будут браться данные
** 		size	- количество байт которые будут скопированны
** INFO:
** 		Копирует данные из source в dst размером size
** 		Функция является универсальной, так как может копировать любые данные
** 		включая структуры, строки, массивы чисел и тд
** EXAMPLE:
** 		IN:
** 			(dst = (address 100), source = (address 500), size = 5)
** 		COPY:
** 			(address 100) ->|0x05	0x70	0x00	0x33	0x77	0x88...|
** 							|		<-		size = 5	->		|
** 			(address 500) ->|0x00	0x00	0x00	0x00	0x00	0x00...|
** 		OUT:
** 			(address 500) ->|0x05	0x70	0x00	0x33	0x77	0x00...|
** RETURN:
** 		По скольку мы копируем точное поведение оригинальной функции,
** 			рассмотрим её поведение:
**
** 				DST		SRC		SIZE
** 			_________________________
** 		IN:		0		0		[1-infinity]
** 		OUT:	(null)
** 			_________________________
** 		IN:		[pnt1]	0		[1-infinity]
** 		OUT:	SEG
** 			_________________________
** 		IN:		[pnt1]	0		0
** 		OUT:	[ptr1]
** 			_________________________
** 		IN:		0		[pnt2]	[1-infinity]
** 		OUT:	SEG
** 			_________________________
** 		IN:		0		[pnt2]	0
** 		OUT:	(null)
** 			_________________________
** 		IN:		[pnt1]	[pnt2]	[n <= доступная память по pnt1]
** 		OUT:	[pnt1]
** 			_________________________
** 		IN:		[pnt1]	[pnt2]	[n > доступная память по pnt1]
** 		OUT:	SEG
*/

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	size_t	counter;

	if (!destination && !source)
		return (0);
	counter = 0;
	while (counter < size)
	{
		((unsigned char *)destination)[counter] = \
			((unsigned char *)source)[counter];
		counter++;
	}
	return (destination);
}
