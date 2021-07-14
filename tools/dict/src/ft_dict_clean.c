/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_clean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 07:41:55 by telron            #+#    #+#             */
/*   Updated: 2021/01/20 18:53:06 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

void	ft_dict_clean(t_dict *dict)
{
	char	**keys;
	size_t	counter;

	keys = ft_dict_get_keys(dict);
	counter = 0;
	while (keys[counter])
		ft_dict_del(dict, keys[counter++]);
	free(keys);
}
