/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_get_keys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 07:51:16 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 18:20:28 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

static void	ft_zeroing_static(size_t *counter, t_dict_elem **elem)
{
	*counter = 0;
	*elem = 0;
}

int	ft_dict_iter_keys(t_dict *dict, char **key)
{
	static size_t		counter_in_hash_table = 0;
	static t_dict_elem	*elem_now = 0;

	if (!dict)
	{
		ft_zeroing_static(&counter_in_hash_table, &elem_now);
		return (0);
	}
	while (counter_in_hash_table < dict->max_elem)
	{
		if (dict->hash_table[counter_in_hash_table])
		{
			if (!elem_now)
				elem_now = dict->hash_table[counter_in_hash_table];
			*key = (char *)elem_now->key;
			elem_now = (t_dict_elem *)elem_now->list.next;
			if (!elem_now)
				counter_in_hash_table++;
			return (1);
		}
		counter_in_hash_table++;
	}
	ft_zeroing_static(&counter_in_hash_table, &elem_now);
	return (0);
}

int	ft_dict_iter_value(t_dict *dict, void **value)
{
	static size_t		counter_in_hash_table = 0;
	static t_dict_elem	*elem_now = 0;

	if (!dict)
	{
		ft_zeroing_static(&counter_in_hash_table, &elem_now);
		return (0);
	}
	while (counter_in_hash_table < dict->max_elem)
	{
		if (dict->hash_table[counter_in_hash_table])
		{
			if (!elem_now)
				elem_now = dict->hash_table[counter_in_hash_table];
			*value = elem_now->list.content;
			elem_now = (t_dict_elem *)elem_now->list.next;
			if (!elem_now)
				counter_in_hash_table++;
			return (1);
		}
		counter_in_hash_table++;
	}
	ft_zeroing_static(&counter_in_hash_table, &elem_now);
	return (0);
}

char	**ft_dict_get_keys(t_dict *dict)
{
	char		**keys;
	size_t		counter;
	size_t		counter_keys;
	t_dict_elem	*buf;

	keys = (char **)ft_calloc(dict->count_elem + 1, sizeof(char *));
	if (!keys)
		return ((char **)0);
	counter = 0;
	counter_keys = 0;
	while (counter < dict->max_elem)
	{
		if (dict->hash_table[counter])
		{
			buf = dict->hash_table[counter];
			while (buf)
			{
				keys[counter_keys++] = (char *)buf->key;
				buf = (t_dict_elem *)buf->list.next;
			}
		}
		counter++;
	}
	keys[counter_keys] = 0;
	return (keys);
}
