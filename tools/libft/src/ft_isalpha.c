/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:48:16 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 18:58:04 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ORIGINAL:
** 		#include <ctype.h>
**
** 		int		isalpha(int c);
** INFO:
** 		Если argument является числом из таблице ASCII
** 		обозначающим букву латинского алфавита
** 		в пределах от 65 до 90 включительно [ABCDEFGHIJKLMNOPQRSTUVWXYZ]
** 		или в пределах от 97 до 122 включительно [abcdefghijklmnopqrstuvwxyz]
** 		вернётся 1, иначе 0
*/

int	ft_isalpha(int argument)
{
	argument &= -33;
	return ('A' <= argument && argument <= 'Z');
}
