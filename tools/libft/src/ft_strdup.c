/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 00:22:20 by telron            #+#    #+#             */
/*   Updated: 2020/11/02 13:10:18 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*result;

	len = ft_strlen(str);
	result = (char *)malloc(len + 1);
	if (!result)
		return ((void *)0);
	ft_memcpy(result, str, len);
	result[len] = '\0';
	return (result);
}
