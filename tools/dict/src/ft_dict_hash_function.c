/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_hash_function.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 07:56:58 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 17:50:29 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

size_t	ft_dict_hash_function(const char *key, size_t max_elem)
{
	size_t	hash;
	size_t	counter;

	hash = 2166136261;
	counter = 0;
	while (key[counter])
	{
		hash += (hash << 1) + \
				(hash << 4) + \
				(hash << 7) + \
				(hash << 8) + \
				(hash << 24);
		hash ^= key[counter];
		counter++;
	}
	return (hash % max_elem);
}
