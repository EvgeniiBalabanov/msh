/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_get_by_user.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 02:09:31 by telron            #+#    #+#             */
/*   Updated: 2021/04/24 17:05:09 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_env_var_get_by_user(t_shell *config, char *key)
{
	t_variable	*variable;

	variable = (t_variable *)ft_dict_get(config->environment, key);
	if (variable && !(variable->attributes & VAR_ATTR_INVISIBLE))
	{
		if (variable->attributes & VAR_ATTR_ISDYNAMIC)
			((void (*)(t_shell *, t_variable *))
				variable->ft_dynamic_value)
					(config, variable);
		return (variable->value);
	}
	return (0);
}
