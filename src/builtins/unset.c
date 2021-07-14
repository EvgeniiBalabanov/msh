/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 21:27:14 by aberry            #+#    #+#             */
/*   Updated: 2021/06/07 14:46:26 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_check_data(const char *str)
{
	size_t	counter;
	int		identifier_error;

	counter = 0;
	identifier_error = !(ft_isalpha(str[0]) || str[counter] == '_');
	while (str[counter] && !identifier_error && str[counter] != '=')
	{
		identifier_error = !(ft_isalnum(str[counter]) || str[counter] == '_');
		counter++;
	}
	return (identifier_error);
}

static int	ft_delete_var(t_shell *config, char *key)
{
	size_t		counter;
	t_variable	*variable;
	int			identifier_error;

	counter = 0;
	identifier_error = ft_check_data(key);
	if (!identifier_error)
	{
		variable = ft_dict_get(config->environment, key);
		if (variable)
		{
			if (!(variable->attributes & VAR_ATTR_NOUNSET))
				ft_env_var_delone(config->environment, 0, key);
			else
			{
				variable->attributes |= VAR_ATTR_INVISIBLE;
				variable->attributes ^= VAR_ATTR_TO_EXECUTBLE;
			}
		}
	}
	return (identifier_error);
}

int	ft_builtin_unset(t_shell *config, const char *argv[])
{
	size_t	counter;
	int		identifier_error;

	counter = 1;
	identifier_error = 0;
	if (!argv)
		return (0);
	while (argv[counter])
	{
		if (ft_delete_var(config, (char *)argv[counter]))
		{
			ft_error_print(config, "unset", argv[counter], \
				"not a valid identifier");
			identifier_error = 1;
		}
		counter++;
	}
	return (identifier_error);
}
