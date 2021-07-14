/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:51:04 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 18:54:37 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	unsigned int	counter;
	char			*result;

	if (!str || !f)
		return ((char *)0);
	result = (char *)malloc(ft_strlen(str) + 1);
	if (!result)
		return ((char *)0);
	counter = 0;
	while (str[counter])
	{
		result[counter] = f(counter, str[counter]);
		counter++;
	}
	result[counter] = '\0';
	return (result);
}
