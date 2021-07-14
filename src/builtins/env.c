/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 21:27:05 by aberry            #+#    #+#             */
/*   Updated: 2021/06/07 20:47:28 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_builtin_env_print(t_shell *config)
{
	t_variable	*variable;

	while (ft_dict_iter_value(config->environment, (void **)&variable))
	{
		if (!(variable->attributes & VAR_ATTR_TO_EXECUTBLE) || \
			(variable->attributes & VAR_ATTR_INVISIBLE))
			continue ;
		if (variable->attributes & VAR_ATTR_ISDYNAMIC)
			((t_ft_dyn_var)variable->ft_dynamic_value)(config, variable);
		if (variable->value_for_exe)
			ft_putendl_fd(variable->value_for_exe, 1);
	}
}

static void	ft_set_executable(t_executable *executable, const char **argv)
{
	executable->argums = argv;
	executable->descriptors.std_in = 0;
	executable->descriptors.std_out = 1;
	executable->descriptors.std_err = 2;
}

int	ft_builtin_env(t_shell *config, char *const argv[])
{
	int				status;
	t_executable	executable;
	pid_t			cpid;

	cpid = fork();
	if (!cpid)
	{
		status = 0;
		while (*++argv && ft_strchr(*argv, '='))
			ft_env_var_init_others(config, &config->environment, *argv, \
				ft_strchr(*argv, '=') - *argv);
		if (*argv)
		{
			ft_set_executable(&executable, (const char **)argv);
			status = ft_launch_executable(config, &executable);
		}
		else
			ft_builtin_env_print(config);
		exit(status);
	}
	waitpid(cpid, &status, 0);
	return (status);
}
