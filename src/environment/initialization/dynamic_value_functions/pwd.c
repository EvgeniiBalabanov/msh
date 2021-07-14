/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 22:07:13 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 01:17:42 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env_var_dv_pwd(\
					t_shell __attribute__((unused)) *config, \
					t_variable *var_pwd)
{
	char	dir[1024];
	char	*value;
	char	*value_for_exe;

	if (!var_pwd->value && getcwd(dir, 1024))
	{
		value = ft_strdup(dir);
		value_for_exe = ft_strjoin("PWD=", value);
		free(var_pwd->value_for_exe);
		if (value && value_for_exe)
		{
			var_pwd->value = value;
			var_pwd->value_for_exe = value_for_exe;
		}
		else
		{
			free(value);
			free(value_for_exe);
			var_pwd->value_for_exe = 0;
		}
	}
}
