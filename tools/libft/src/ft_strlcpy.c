/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:46:39 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 19:06:08 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ORIGINAL:
** 	#include <string.h>
**
** 	size_t
** 	strlcpy(char *restrict dst, const char *restrict src, size_t dstsize);
** FUNCTION NAME:
** 		ft_strlcpy
** INPUT PARAMS:
** 		dst		- адрес куда будет производиться копирование
** 		src		- строка откуда будет браться информация
** 		size	- длина строки для копирования - 1 (на нуль терминатор)
** INFO:
** 		Копирует строку из src в dst не более size байт,
** 		последный байт гарантированно закрывается нуль терминатором
** EXAMPLE:
** 		IN:
** 			dst = "Hello"
** 			src = "World"
** 			size = 4
** 			(dst = (address dst), src = (address src), size = 4)
** 		PROCESS:
** 			IN:
** 				src  ->	|'H''e''l''l''o''\0'|
** 				size ->	|<- size=4 ->|
** 				dst  ->	|'W''o''r''l''d''\0'|
** 			RESULT:
** 				dst  ->	|'H''e''l''\0'|
** 						"Hel"
** RETURN:
** 		Возвращает длину src
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len_with_end;
	char	*end_res;

	if (!dst || !src)
		return ((size_t)0);
	if (size)
	{
		end_res = ft_memccpy(dst, src, 0, size - 1);
		len_with_end = size;
		if (end_res)
			len_with_end = (size_t)(end_res - dst);
		dst[len_with_end - 1] = 0;
	}
	return (ft_strlen(src));
}
