/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:37:32 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 18:50:48 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ORIGINAL:
** 		#include <string.h>
**
** 		void	*memmove(void *dst, const void *src, size_t len);
** FUNCTION NAME:
** 		ft_memmove
** INPUT PARAMS:
** 		dst		- desctination, адрес по которому будут записаны данные
** 		src		- source, адрес из которого будут браться данные
** 		size	- количество байт которые будут скопированны
** INFO:
** 		Копирует данные из src в dst размером size
** 		Та же memcpy, но с одним исключением,
** 		у memmove есть защита от перекрытия,
** 		что позволяет подавать на вход один и тот же объект
** EXAMPLE:
** 		IN:
** 			char *str = "Scroll World";
** 			(dst = (address str+1), src = (address str), size = 3)
** 		MEMCPY:
** 			SRC:(address str)	->	|'S' 'c' 'r' 'o' 'l' ' '...|
** 									|<-size=3->|
** 			DST:(address str+2)	->	|'c' 'r' 'o' 'l' 'l'...|
**
** 			RESULT:					|'S' 'S' 'S' 'l'..|
** 			(необределённое поведение, вызвать такое поведение
** 						достаточно сложно в оригинальной функции)
** 		MEMMOVE:
** 			SRC:(address str)	->	|'S' 'c' 'r' 'o' 'l' ' '...|
** 									|<-size=3->|
** 			DST:(address str+2)	->	|'c' 'r' 'o' 'l' 'l'...|
**
** 			RESULT:					|'S' 'c' 'l' 'l'..|
** 			(В данном случае несмотря на перекрытие
** 						копирование прошло успешно)
*/

void	*ft_memmove(void *destination, const void *source, size_t size)
{
	size_t	counter;
	size_t	index;

	if (!destination && !source)
		return (0);
	counter = 0;
	while (counter < size)
	{
		if (destination < source)
			index = counter;
		else
			index = size - counter - 1;
		((unsigned char *)destination)[index] = \
			((unsigned char *)source)[index];
		counter++;
	}
	return (destination);
}
