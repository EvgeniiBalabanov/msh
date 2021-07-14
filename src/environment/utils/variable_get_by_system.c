/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_get_by_system.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:58:34 by telron            #+#    #+#             */
/*   Updated: 2021/02/15 16:58:53 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_env_var_get_by_system(t_shell *config, char *key)
{
	t_variable	*variable;

	variable = (t_variable *)ft_dict_get(config->environment, key);
	if (variable)
	{
		if (variable->attributes & VAR_ATTR_ISDYNAMIC)
			((void (*)(t_shell *, t_variable *))
				variable->ft_dynamic_value)
					(config, variable);
		return (variable->value);
	}
	return (0);
}
