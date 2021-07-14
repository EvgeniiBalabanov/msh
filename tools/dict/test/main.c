/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:17:19 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 18:35:24 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict_test.h"

int	main(void)
{
	t_dict		*dict;
	void		*value;
	char		*key;

	dict = ft_dict_init_pro(128);
	ft_dict_add(&dict, "1", "one");
	ft_dict_add(&dict, "2", "two");
	ft_dict_add(&dict, "3", "three");
	ft_dict_add(&dict, "4", "four");
	ft_dict_add(&dict, "5", "five");
	ft_dict_add(&dict, "6", "six");
	ft_dict_add(&dict, "7", "два");
	ft_dict_add(&dict, "3", "no three");
	while (ft_dict_iter_keys(dict, &key) && ft_dict_iter_value(dict, &value))
	{
		printf("hash_index -> |%zu|\nkey -> |%s|\nvalue -> |%s|\n\n", \
			ft_dict_hash_function(\
				(const char *)key, dict->max_elem), key, (char *)value);
	}
	return (0);
}
