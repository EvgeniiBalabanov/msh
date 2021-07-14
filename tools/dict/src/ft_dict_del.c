/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 07:39:07 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 17:53:51 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

void	ft_dict_del(t_dict *dict, const char *key)
{
	t_dict_elem	*elem;
	t_dict_elem	*last;
	size_t		index;

	index = ft_dict_hash_function(key, dict->max_elem);
	elem = dict->hash_table[index];
	last = 0;
	while (elem)
	{
		if (!ft_strcmp(elem->key, key))
		{
			if (last)
				last->list.next = elem->list.next;
			else
				dict->hash_table[index] = (t_dict_elem *)elem->list.next;
			free(elem);
			dict->count_elem--;
			return ;
		}
		last = elem;
		elem = (t_dict_elem *)elem->list.next;
	}
}
