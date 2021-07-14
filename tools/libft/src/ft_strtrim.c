/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:53:31 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 18:54:31 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** FUNCTION NAME:
** 		ft_strtrim
** INPUT PARAMS:
** 		str		- строка для обработки
** 		pattern	- набор символов
** INFO:
** 		Создаёт новую строку на основе str,
** 		но обрезаную слево и справо по символам из pattern.
** 		Если в серидине, тоже находятся символы из pattern, они остаются.
** EXAMPLE:
** 		IN:
** 			str = "xyBLAyzBLAzx"
** 			pattern = "xyz"
** 			(str = (address str), pattern = (address pattern))
** 		PROCESS:
** 			IN:
** 				str ->	|'x' 'y' 'B' 'L' 'A' 'y' 'z' 'B' 'L' 'A' 'z' 'x'|
** 						|'>' '>' 'V' 'V' 'V' 'V' 'V' 'V' 'V' 'V' '<' '<'|
** 						(V - символы полученой строки)
** 			RESULT:
** 								|'B' 'L' 'A' 'y' 'z' 'B' 'L' 'A'| + |'\0'|
** 								"BLAyzBLA"
** RETURN:
** 		Получившиеся строка
** 		или NULL если:
** 			1) str		== 0
** 			2) pattrern	== 0
** 			3) Память под строку не была выделена
*/

char	*ft_strtrim(char const *str, char const *pattern)
{
	size_t	start;
	size_t	len;

	if (!str || !pattern)
		return ((char *)0);
	start = 0;
	while (str[start] && ft_strchr(pattern, str[start]))
		start++;
	len = ft_strlen(str + start);
	while (len && str[len + start - 1] && \
		ft_strchr(pattern, str[len + start - 1]))
		len--;
	return (ft_substr(str, start, len));
}
