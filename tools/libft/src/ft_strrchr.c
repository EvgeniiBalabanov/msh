/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 21:05:11 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 18:58:26 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ORIGINAL:
** 		#include <string.h>
**
** 		char	*strrchr(const char *s, int c);
** FUNCTION NAME:
** 		ft_strchr
** INPUT PARAMS:
** 		string		- адрес строки по которой будет происходить поиск
** 		c_pattern	- искомый символ в строке
** INFO:
** 		Производит поиск символа c_pattern в строке string,
** 		поиск идёт справо налево, до первого вхождения
** EXAMPLE:
** 		IN:
** 			(string = (address 100), c_pattern = 'd')
** 		PROCESS:
** 														c_pattern
** 															V
** 			(address 100) ->|'F''i''n''d'' ''m''e'' ''d''u''d''e''\0'|
** 		OUT:
** 			(address 103) ->							  |'d''e''\0'|
** RETURN:
** 		Адрес где был найден искобый символ, или 0 poiner если небыло совпадений
*/

char	*ft_strrchr(const char *string, int c_pattern)
{
	char	*result;

	result = 0;
	if (!c_pattern)
		return ((char *)string + ft_strlen(string));
	while (*string)
	{
		if (*string == c_pattern)
			result = (char *)string;
		string++;
	}
	return (result);
}
