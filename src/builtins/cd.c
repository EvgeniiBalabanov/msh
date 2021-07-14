/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 21:26:58 by aberry            #+#    #+#             */
/*   Updated: 2021/06/07 14:42:18 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_chdir(t_shell *config, const char *path)
{
	t_variable	*var_pwd;

	errno = 0;
	var_pwd = ft_dict_get(config->environment, "PWD");
	if (!var_pwd)
	{
		ft_error_print(config, "cd", "malloc", "variable in dict");
		return (12);
	}
	((t_ft_dyn_var)var_pwd->ft_dynamic_value)(config, var_pwd);
	if (!chdir(path) || !chdir(path))
	{
		ft_env_oldpwd_reload(config);
		free(var_pwd->value);
		var_pwd->attributes &= ~VAR_ATTR_INVISIBLE;
		var_pwd->value = 0;
	}
	else
	{
		ft_error_print(config, "cd", path, strerror(errno));
		errno = 0;
		return (1);
	}
	return (0);
}

static int	ft_cd_home(t_shell *config)
{
	char	*home;

	home = ft_env_var_get_by_user(config, "HOME");
	if (home)
	{
		if (!ft_strcmp(home, ""))
			home = ".";
		return (ft_chdir(config, home));
	}
	ft_error_print(config, "cd", "HOME", "not set");
	return (1);
}

static int	ft_cd_oldpwd(t_shell *config)
{
	char	*oldpwd;

	oldpwd = ft_env_var_get_by_user(config, "OLDPWD");
	if (oldpwd)
	{
		ft_putendl_fd(oldpwd, 1);
		if (!ft_strcmp(oldpwd, ""))
			oldpwd = ".";
		return (ft_chdir(config, oldpwd));
	}
	ft_error_print(config, "cd", "OLDPWD", "not set");
	return (1);
}

int	ft_builtin_cd(t_shell *config, const char *argv[])
{
	if (!argv[1] || !ft_strcmp(argv[1], "--"))
		return (ft_cd_home(config));
	else if (!ft_strcmp(argv[1], "-"))
		return (ft_cd_oldpwd(config));
	return (ft_chdir(config, argv[1]));
}
