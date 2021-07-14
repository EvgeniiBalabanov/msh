/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oldpwd_reload.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 21:04:32 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 05:11:56 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env_oldpwd_reload(t_shell *config)
{
	t_variable	*pwd;
	t_variable	*oldpwd;
	char		*value;
	char		*value_for_exe;

	pwd = ft_dict_get(config->environment, "PWD");
	oldpwd = ft_dict_get(config->environment, "OLDPWD");
	if (!(pwd && oldpwd && pwd->value))
		return ;
	value = ft_strdup(pwd->value);
	value_for_exe = ft_strjoin("OLDPWD=", pwd->value);
	if (value && value_for_exe)
	{
		free(oldpwd->value);
		free(oldpwd->value_for_exe);
		oldpwd->value = value;
		oldpwd->value_for_exe = value_for_exe;
		oldpwd->attributes = pwd->attributes & \
			(VAR_ATTR_INVISIBLE | VAR_ATTR_NOUNSET | VAR_ATTR_TO_EXECUTBLE);
	}
	else
	{
		free(value);
		free(value_for_exe);
	}
}
