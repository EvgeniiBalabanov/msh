/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 07:44:26 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 17:49:21 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

static int	ft_add_or_change_elem(\
						const char *key, \
						void *value, \
						t_dict_elem **now)
{
	t_dict_elem	*elem;

	elem = ft_dict_get_elem_by_key(*now, key);
	if (elem)
	{
		elem->list.content = value;
		return (0);
	}
	elem = ft_dict_elem_init(key, value);
	if (!elem)
		return (-1);
	ft_lstadd_back((t_list **)now, (t_list *)elem);
	return (0);
}

int	ft_dict_add(t_dict **dict, const char *key, void *value)
{
	size_t		index;
	t_dict_elem	*now;
	t_dict_elem	*elem;

	if ((double)((*dict)->count_elem) > 0.7 * (double)((*dict)->max_elem))
		if (ft_dict_double(dict) == -1)
			return (-1);
	index = ft_dict_hash_function(key, (*dict)->max_elem);
	now = (*dict)->hash_table[index];
	if (!now)
	{
		elem = ft_dict_elem_init(key, value);
		if (!elem)
			return (-1);
		(*dict)->hash_table[index] = elem;
	}
	else if (ft_add_or_change_elem(key, value, &now))
		return (-1);
	(*dict)->count_elem++;
	return (0);
}
