/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:43:07 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 05:10:27 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env_delete_env(t_shell *config)
{
	char	*key;

	while (ft_dict_iter_keys(config->environment, &key))
	{
		ft_env_var_delone(config->environment, 0, key);
	}
	ft_dict_rem(config->environment);
}
