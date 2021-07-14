/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_delone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 20:39:45 by aberry            #+#    #+#             */
/*   Updated: 2021/06/07 05:10:38 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env_var_delone(\
					t_dict *environment, \
					t_variable *variable, \
					const char *key)
{
	t_variable		*variable_del;

	variable_del = 0;
	if (key)
	{
		variable_del = (t_variable *)ft_dict_get(environment, key);
		if (variable_del)
			ft_dict_del(environment, key);
	}
	if (variable)
		variable_del = variable;
	if (variable_del)
	{
		free(variable_del->name);
		free(variable_del->value_for_exe);
		free(variable_del->value);
		free(variable_del);
	}
}
