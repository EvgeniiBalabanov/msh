/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:38:12 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 18:57:52 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ORIGINAL:
** 		#include <strings.h>
**
** 		void	*memset(void *b, int c, size_t len);
** FUNCTION NAME:
** 		ft_memset
** INPUT PARAMS:
** 		destination	- адрес по которому нужно сделать изменение
** 		value		- значение каждого байта после изменения
** 		count		- количество байт для изменения
** INFO:
** 		Изменяет каждый байт по адресу destination
** 		в количестве size байт на значение value
** EXAMPLE:
** 		IN:
** 			(destination = (address 100), value = 0x41, size = 5)
** 		COPY:
** 			(address 100) ->|0x05	0x70	0x00	0x33	0x77	0x88...|
** 							|		<-		size = 5	->		|
** 		OUT:
** 			(address 100) ->|0x41	0x41	0x41	0x41	0x41	0x88...|
*/

void	*ft_memset(void *destination, int value, size_t size)
{
	unsigned char	*result;

	result = (unsigned char *)destination;
	while (size--)
		result[size] = (unsigned char)value;
	return (destination);
}
