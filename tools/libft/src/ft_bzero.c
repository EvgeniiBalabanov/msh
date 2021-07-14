/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:49:38 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 19:04:02 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ORIGINAL:
** 		#include <strings.h>
**
** 		void	bzero(void *s, size_t n);
** FUNCTION NAME:
** 		ft_bzero
** INPUT PARAMS:
** 		destination	- адрес по которому нужно сделать зануление
** 		count		- количество байт для зануления
** INFO:
** 		Обнуляет данные по адресу destination в количестве size байт
** 		Функция схожа с memset, и зачастую реальзуется как
** 			memset(void *destination, 0, size_t size)
** EXAMPLE:
** 		IN:
** 			(destination = (address 100), size = 5)
** 		COPY:
** 			(address 100) ->|0x05	0x70	0x00	0x33	0x77	0x88...|
** 							|		<-		size = 5	->		|
** 		OUT:
** 			(address 100) ->|0x00	0x00	0x00	0x00	0x00	0x88...|
*/

void	*ft_bzero(void *destination, size_t size)
{
	unsigned char	*result;

	result = (unsigned char *)destination;
	while (size--)
		result[size] = 0;
	return (destination);
}
