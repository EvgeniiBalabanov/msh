/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:09:05 by telron            #+#    #+#             */
/*   Updated: 2020/11/07 00:16:01 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ORIGINAL:
** 		#include <string.h>
**
** 		void	*memchr(const void *s, int c, size_t n);
** FUNCTION NAME:
** 		ft_memccpy
** INPUT PARAMS:
** 		pointer	- адрес по которому будет происходить поиск
** 		value	- искомое значения байта
** 		size	- диапазон в байтах, которые могут быть скопированы
** INFO:
** 		Производит поиск байта value по адресу pointer, не более size байт
** EXAMPLE:
** 		IN:
** 			(pointer = (address 100), value = 0x33, size = 5)
** 		PROCESS:
** 													value
** 													 V
** 			(address 100) ->|0x05	0x70	0x00	0x33	0x77	0x88...|
** 							|		<-		size = 5	->		|
** 		OUT:
** 			(address 103) ->						|0x33	0x05	0x06...|
** RETURN:
** 		Адрес где был найден искобый байт, или 0 poiner если небыло совпадений
*/

void	*ft_memchr(const void *pointer, int value, size_t size)
{
	size_t			counter;
	unsigned char	*result;

	counter = 0;
	result = (unsigned char *)pointer;
	while (counter < size)
	{
		if (result[counter] == (unsigned char)value)
			return (result + counter);
		counter++;
	}
	return ((void *)0);
}
