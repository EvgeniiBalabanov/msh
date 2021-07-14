/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:54:53 by aberry            #+#    #+#             */
/*   Updated: 2021/06/07 01:15:58 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_sort_array_str(char **array)
{
	size_t		i;
	size_t		j;
	char		*tmp;

	i = 0;
	while (array[i])
	{
		j = 1 + i;
		while (array[j])
		{
			if (ft_strcmp(array[i], array[j]) > 0)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	ft_print_result(t_shell *config, t_variable *variable)
{
	ft_putstr_fd("declare -x ", 1);
	ft_putstr_fd(variable->name, 1);
	if (variable->attributes & VAR_ATTR_ISDYNAMIC && \
		variable->ft_dynamic_value)
		((t_ft_dyn_var)variable->ft_dynamic_value)(config, variable);
	if (variable->value)
	{
		ft_putstr_fd("=\"", 1);
		ft_putstr_fd(variable->value, 1);
		ft_putchar_fd('\"', 1);
	}
	ft_putchar_fd('\n', 1);
}

int	ft_env_print_for_export(t_shell *config)
{
	t_variable	*variable;
	char		**keys;
	size_t		counter;

	counter = 0;
	keys = ft_dict_get_keys(config->environment);
	if (!keys)
	{
		ft_error_print(config, "export", "malloc", "change or add");
		return (12);
	}
	ft_sort_array_str(keys);
	while (keys[counter])
	{
		variable = ft_dict_get(config->environment, keys[counter]);
		if (variable && (variable->attributes & VAR_ATTR_TO_EXECUTBLE) && \
				!(variable->attributes & VAR_ATTR_INVISIBLE))
			ft_print_result(config, variable);
		counter++;
	}
	free(keys);
	return (0);
}
