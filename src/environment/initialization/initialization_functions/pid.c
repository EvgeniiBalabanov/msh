/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 22:07:27 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 01:25:04 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env_var_init_pid(\
					t_shell __attribute__((unused)) *config, \
					t_dict **environment, \
					void *ft_dynamic_value)
{
	pid_t		main_pid;
	char		*string_pid;
	char		*value_for_exe;
	t_variable	*variable;

	main_pid = getpid();
	string_pid = ft_itoa(main_pid);
	if (!string_pid)
		return ;
	value_for_exe = ft_strjoin("$=", string_pid);
	if (value_for_exe)
	{
		variable = ft_env_var_new(environment, value_for_exe, 1);
		if (variable)
		{
			variable->attributes = (VAR_ATTR_READONLY | VAR_ATTR_NOUNSET);
			if (ft_dynamic_value)
			{
				variable->attributes |= VAR_ATTR_ISDYNAMIC;
				variable->ft_dynamic_value = ft_dynamic_value;
			}
		}
	}
	free(string_pid);
	free(value_for_exe);
}
