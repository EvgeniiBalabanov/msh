/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:49:35 by telron            #+#    #+#             */
/*   Updated: 2021/01/08 14:55:35 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ORIGINAL:
** 		#include <string.h>
**
** 		char	*strchr(const char *s, int c);
** FUNCTION NAME:
** 		ft_strchr
** INPUT PARAMS:
** 		string		- адрес строки по которой будет происходить поиск
** 		c_pattern	- искомый символ в строке
** INFO:
** 		Производит поиск символа c_pattern в строке string,
** 		поиск идёт слево направо, до первого вхождения
** EXAMPLE:
** 		IN:
** 			(string = (address 100), c_pattern = 'd')
** 		PROCESS:
** 									c_pattern
** 									   V
** 			(address 100) ->|'F''i''n''d'' ''m''e'' ''d''u''d''e''\0'|
** 		OUT:
** 			(address 103) ->		 |'d'' ''m''e'' ''d''u''d''e''\0'|
** RETURN:
** 		Адрес где был найден искобый символ, или 0 poiner если небыло совпадений
*/

char	*ft_strchr(const char *string, int c_pattern)
{
	return (ft_memchr(string, c_pattern, ft_strlen(string) + 1));
}
