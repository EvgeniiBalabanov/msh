/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_get_elem_by_key.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 07:52:15 by telron            #+#    #+#             */
/*   Updated: 2021/03/01 05:45:41 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

t_dict_elem	*ft_dict_get_elem_by_key(t_dict_elem *elem, const char *key)
{
	while (elem)
	{
		if (!ft_strcmp(elem->key, key))
			return (elem);
		elem = (t_dict_elem *)elem->list.next;
	}
	return (0);
}
