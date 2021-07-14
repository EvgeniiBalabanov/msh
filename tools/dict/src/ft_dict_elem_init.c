/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_elem_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 07:47:17 by telron            #+#    #+#             */
/*   Updated: 2021/03/01 05:24:33 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

t_dict_elem	*ft_dict_elem_init(const char *key, void *value)
{
	t_dict_elem	*result;

	result = (t_dict_elem *)ft_calloc(1, sizeof(t_dict_elem));
	if (!result)
		return (0);
	result->key = key;
	result->list.content = value;
	return (result);
}
