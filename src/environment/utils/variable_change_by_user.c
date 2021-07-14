/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_change_by_user.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:42:25 by telron            #+#    #+#             */
/*   Updated: 2021/06/09 22:12:47 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ft_get_index(const char *import_variable)
{
	size_t		index_equally;

	index_equally = 0;
	while (1)
	{
		if (import_variable[index_equally] == '=')
			break ;
		else if (!import_variable[index_equally++])
		{
			index_equally = -1;
			break ;
		}
	}
	return (index_equally);
}

static void	ft_uninvisible(t_variable *variable)
{
	if (variable->attributes & VAR_ATTR_INVISIBLE)
	{
		variable->attributes ^= VAR_ATTR_INVISIBLE;
		variable->attributes |= VAR_ATTR_TO_EXECUTBLE;
	}
}

static void	ft_set_value(\
						t_variable *variable, \
						char *value, \
						char *value_for_exe)
{
	if (value && value_for_exe)
	{
		free(variable->value);
		free(variable->value_for_exe);
		variable->value = value;
		variable->value_for_exe = value_for_exe;
	}
	else
	{
		free(value);
		free(value_for_exe);
	}
}

t_variable	*ft_env_var_change_by_user(\
						t_shell *config, \
						const char *import_variable)
{
	t_variable	*variable;
	size_t		index_equally;
	char		*value;
	char		*value_for_exe;
	char		*key;

	index_equally = ft_get_index(import_variable);
	key = ft_substr(import_variable, 0, index_equally);
	variable = (t_variable *)ft_dict_get(config->environment, key);
	free(key);
	if (!variable)
	{
		variable = ft_env_var_new(&config->environment, \
				import_variable, index_equally);
		variable->attributes = VAR_ATTR_TO_EXECUTBLE;
	}
	else if (!(variable->attributes == VAR_ATTR_READONLY) && \
		index_equally != (size_t)(-1))
	{
		value = ft_strdup(import_variable + index_equally + 1);
		value_for_exe = ft_strdup(import_variable);
		ft_set_value(variable, value, value_for_exe);
		ft_uninvisible(variable);
	}
	return (variable);
}
