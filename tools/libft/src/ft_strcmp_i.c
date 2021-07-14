/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 19:56:16 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 19:07:24 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp_i(const char *str1, const char *str2)
{
	while (*str1 || *str2)
	{
		if (ft_tolower(*str1) != ft_tolower(*str2))
			return ((unsigned char)(*str1) - (unsigned char)(*str2));
		str1++;
		str2++;
	}
	return (0);
}
