/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 22:07:20 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 01:23:24 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env_var_init_home(t_shell __attribute__((unused)) *config, \
								t_dict **environment, void *ft_dynamic_value)
{
	t_variable			*variable;
	int					flag_invisible;

	flag_invisible = 0;
	variable = ft_dict_get(*environment, "HOME");
	if (!variable)
	{
		variable = ft_env_var_new(environment, "HOME=", 4);
		flag_invisible = 1;
	}
	if (variable)
	{
		variable->attributes = 0;
		variable->attributes |= VAR_ATTR_TO_EXECUTBLE;
		variable->attributes |= VAR_ATTR_NOUNSET;
		if (ft_dynamic_value)
		{
			variable->attributes |= VAR_ATTR_ISDYNAMIC;
			variable->ft_dynamic_value = ft_dynamic_value;
		}
		if (flag_invisible)
			variable->attributes |= VAR_ATTR_INVISIBLE;
	}
}
