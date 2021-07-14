/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:14:41 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 18:56:10 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t size)
{
	size_t	counter;

	counter = 0;
	while (counter < size)
	{
		if ((str1[counter] != str2[counter]) || !str1[counter])
		{
			return ((unsigned char)str1[counter] - \
				(unsigned char)str2[counter]);
		}
		counter++;
	}
	return (0);
}
