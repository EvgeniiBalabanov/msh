/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:50:13 by telron            #+#    #+#             */
/*   Updated: 2021/01/08 15:11:45 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** FUNCTION NAME:
** 		ft_strjoin
** INPUT PARAMS:
** 		str_1	- строка которая будет стоять в начале
** 		str_2	- строка которая будет стоять в конце
** INFO:
** 		Создаёт новую строку, путём объединения строки str_1 и str_2
** EXAMPLE:
** 		IN:
** 			str_1 = "Hello"
** 			str_2 = "World"
** 			(str_1 = (address str_1), str_2 = (address str_2))
** 		PROCESS:
** 			IN:
** 				str_1 ->   |'H' 'e' 'l' 'l' 'o'	'\0'|
** 				str_2 ->						|'W' 'o' 'r' 'l' 'd' '\0'|
** 			RESULT:
** 						   |'H' 'e' 'l' 'l' 'o' 'W' 'o' 'r' 'l' 'd' '\0'|
** 							"HelloWorld"
** RETURN:
** 		Получившиеся строка
** 		или NULL если:
** 			1) str_1	== 0
** 			2) str_2	== 0
** 			3) Память под строку не была выделена
*/

char	*ft_strjoin(char const *str_1, char const *str_2)
{
	size_t	len_1;
	size_t	len_2;
	char	*result;

	if (!str_1 || !str_2)
		return ((char *)0);
	len_1 = ft_strlen(str_1);
	len_2 = ft_strlen(str_2);
	result = (char *)malloc(len_1 + len_2 + 1);
	if (!result)
		return ((char *)0);
	ft_memcpy(result, str_1, len_1);
	ft_memcpy(result + len_1, str_2, len_2);
	result[len_1 + len_2] = '\0';
	return (result);
}
