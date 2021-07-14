/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 22:07:32 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 01:23:55 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env_var_init_random(t_shell __attribute__((unused)) *config, \
								t_dict **environment, \
								void *ft_dynamic_value)
{
	t_variable			*variable;
	int					flag_invisible;

	flag_invisible = 0;
	variable = ft_env_var_new(environment, "RANDOM", -1);
	if (variable)
	{
		variable->attributes = 0;
		variable->attributes |= VAR_ATTR_NOUNSET;
		variable->attributes |= VAR_ATTR_ISDYNAMIC;
		variable->ft_dynamic_value = ft_dynamic_value;
		if (flag_invisible)
			variable->attributes |= VAR_ATTR_INVISIBLE;
	}
}
