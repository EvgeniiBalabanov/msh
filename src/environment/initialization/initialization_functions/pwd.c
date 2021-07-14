/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 22:07:29 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 01:20:45 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env_var_init_pwd(t_shell __attribute__((unused)) *config, \
								t_dict **environment, void *ft_dynamic_value)
{
	t_variable	*var_pwd;

	var_pwd = ft_env_var_new(environment, "PWD", -1);
	if (var_pwd)
	{
		var_pwd->attributes = \
			(VAR_ATTR_NOUNSET | VAR_ATTR_TO_EXECUTBLE | VAR_ATTR_ISDYNAMIC);
		var_pwd->ft_dynamic_value = ft_dynamic_value;
	}
}
