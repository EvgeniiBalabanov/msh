/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 23:45:25 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 18:48:28 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ORIGINAL:
** 		#include <stdlib.h>
**
** 		int		atoi(const char *str);
** FUNCTION NAME:
** 		ft_atoi
** INPUT PARAMS:
** 		string	- Строка для перевода в int
** INFO:
** 		Берёт string и конвертирует её в тип int,
** 		предварительно убирая символы isspace в начале
** EXAMPLE:
** 		IN:
** 			string = " \n-123ab"
** 			(string = (address string))
** 		CONVERT:
** 			|' ''\n''-''1''2''3''a''b'|
** 			| >  >   M '1''2''3'|<-stop|
** 			(> - Пропустили. M - Запомнили)
** 		OUT:
** 			-123
** RETURN:
** 		Полученый int в результате конвертации
*/

int	ft_atoi(const char *string)
{
	int		positive;
	size_t	result;

	result = 0;
	positive = 1;
	while ((9 <= *string && *string <= 13) || *string == ' ')
		string++;
	if (*string == '+' || *string == '-')
		if (*string++ == '-')
			positive = -1;
	while (ft_isdigit(*string))
		result = result * 10 + (size_t)(*string++ - '0');
	return ((int)(result * positive));
}
