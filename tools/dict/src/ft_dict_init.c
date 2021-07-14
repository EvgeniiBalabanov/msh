/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 07:48:07 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 17:49:48 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

t_dict	*ft_dict_init_pro(size_t max_elem)
{
	t_dict	*result;

	result = (t_dict *)malloc(sizeof(t_dict));
	if (!result)
	{
		return ((t_dict *)0);
	}
	result->count_elem = 0;
	result->max_elem = max_elem;
	result->hash_table = (t_dict_elem **)ft_calloc(\
		(result->max_elem + 1), \
		sizeof(t_dict_elem *));
	if (!result->hash_table)
	{
		free(result);
		return ((t_dict *)0);
	}
	return (result);
}

t_dict	*ft_dict_init(void)
{
	return (ft_dict_init_pro(8));
}
