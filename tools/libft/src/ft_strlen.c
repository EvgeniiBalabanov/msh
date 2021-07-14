/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:15:34 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 19:05:06 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ORIGINAL:
** 		#include <string.h>
**
** 		size_t	strlen(const char *s);
** FUNCTION NAME:
** 		ft_strlen
** INPUT PARAMS:
** 		string	- строка для подсчёта
** INFO:
** 		Функция считает количество символов в строке, без '\0'
** EXAMPLE:
** 		IN:
** 			string	-> "Hello"
** 			(string = (address string))
** 		PROCESS:
** 			|'H''e''l''l''o''\0'	|
** 			| 1  2  3  4  5 |<-stop	|
** 		OUT:
** 			5
** RETURN:
** 		1) Длина входящей строки
*/

size_t	ft_strlen(const char *string)
{
	size_t	counter;

	counter = 0;
	while (string[counter])
		counter++;
	return (counter);
}
