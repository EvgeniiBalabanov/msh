/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 21:27:08 by aberry            #+#    #+#             */
/*   Updated: 2021/06/07 14:52:11 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_check_data(t_shell *config, const char *str)
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
	if (identifier_error)
		ft_error_print(config, "export", str, "not a valid identifier");
	return (identifier_error);
}

int	ft_builtin_export(t_shell *config, const char *argv[])
{
	size_t	counter;
	int		identifier_error;

	counter = 1;
	identifier_error = 0;
	if (!argv[counter])
		return (ft_env_print_for_export(config));
	while (argv[counter])
	{
		if (!ft_check_data(config, argv[counter]))
		{
			if (!ft_env_var_change_by_user(config, argv[counter]))
			{
				ft_error_print(config, "export", "malloc", "change or add");
				return (12);
			}
		}
		else
			identifier_error = 1;
		counter++;
	}
	return (identifier_error);
}
