/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 07:46:11 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 17:33:31 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

int	ft_dict_double(t_dict **dict)
{
	t_dict	*result;
	char	**keys;
	size_t	counter;

	result = ft_dict_init_pro((*dict)->max_elem * 2);
	if (!result)
		return (-1);
	counter = 0;
	keys = ft_dict_get_keys(*dict);
	while (keys[counter])
	{
		if (ft_dict_add(&result, keys[counter], \
			ft_dict_get(*dict, keys[counter])) == -1)
		{
			ft_dict_rem(result);
			return (-1);
		}
		counter++;
	}
	ft_dict_rem(*dict);
	*dict = result;
	free(keys);
	return (0);
}
