/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 22:07:35 by telron            #+#    #+#             */
/*   Updated: 2021/06/29 08:50:02 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_string_only_set(char *str, const char *set)
{
	if (!str || !*str)
		return (0);
	while (*str)
		if (!ft_strchr(set, *str++))
			return (0);
	return (1);
}

void	ft_env_var_init_shlvl(t_shell __attribute__((unused)) *config, \
							t_dict **environment, void *ft_dynamic_value)
{
	char		*value;
	t_variable	*variable;

	value = (char *)0;
	variable = ft_dict_get(*environment, "SHLVL");
	if (!variable)
		variable = ft_env_var_new(environment, "SHLVL=1", 5);
	else
	{
		if (!ft_string_only_set(variable->value, "0123456789"))
			value = ft_strdup("1");
		else
			value = ft_itoa(ft_atoi(variable->value) + 1);
		if (value)
		{
			free(variable->value_for_exe);
			free(variable->value);
			variable->value = value;
			variable->value_for_exe = ft_strjoin("SHLVL=", value);
		}
	}
	variable->ft_dynamic_value = ft_dynamic_value;
	variable->attributes = VAR_ATTR_TO_EXECUTBLE;
}
