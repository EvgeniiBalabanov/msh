/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:06:42 by telron            #+#    #+#             */
/*   Updated: 2020/11/21 00:25:13 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ORIGINAL:
** 		#include <string.h>
**
** 		char	*strnstr(const char *haystack, const char *needle, size_t len);
** FUNCTION NAME:
** 		ft_strnstr
** INPUT PARAMS:
** 		string	- строка по которой проходит поиск
** 		pattern	- подстрока, которую нужно найти в основной строке
** 		size	- диапазон поиска
** INFO:
** 		Функция находит первое вхождение pattern в string с диапазоном
** 		поиска не более чем size и возвращает указатель
** 		на первый элемент данного вхождения
** EXAMPLE:
** 		IN:
** 			string	-> "Please find me"
** 			pattern	-> "find"
** 			size	-> 14
** 			(string = (address string), pattern = (address pattern), size = 14)
** 		PROCESS:
** 			|'P''l''e''a''s''e'' ''f''i''n''d'' ''m''e'|
** 			|		<-			size = 13	->		|
** 			| >  >  >  >  >  >  > 'f''i''n''d'' ''m' < |
** 			(Шагаем слево, и ищем pattern)			(Не больше чем size)
** 		OUT:
** 			Указатель на 'f'("ind me") в строке string
** RETURN:
** 		1) Указатель на строку, в случае нахождения pattern
** 		2) Значение string, если pattern - пустая строка
** 		3) NULL-poiter, если pattern не был найден
*/

char	*ft_strnstr(const char *string, const char *pattern, size_t size)
{
	size_t	len_ptrn;

	if (!*pattern)
		return ((char *)string);
	len_ptrn = ft_strlen(pattern);
	while (*string && len_ptrn <= size--)
	{
		if (!ft_strncmp(string, pattern, len_ptrn))
			return ((char *)string);
		string++;
	}
	return ((char *)0);
}
