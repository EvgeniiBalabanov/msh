/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 03:30:57 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 19:47:04 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *destination, const char *source)
{
	size_t	counter;

	counter = 0;
	while (1)
	{
		destination[counter] = source[counter];
		if (!destination[counter])
			break ;
		counter++;
	}
	return (destination);
}
