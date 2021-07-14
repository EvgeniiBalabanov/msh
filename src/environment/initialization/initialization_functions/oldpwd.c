/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oldpwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 22:07:21 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 01:23:18 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env_var_init_oldpwd(t_shell __attribute__((unused)) *config, \
								t_dict **environment, void *ft_dynamic_value)
{
	t_variable	*var_oldpwd;

	var_oldpwd = ft_env_var_new(environment, "OLDPWD", -1);
	if (var_oldpwd)
	{
		var_oldpwd->attributes = (VAR_ATTR_NOUNSET | VAR_ATTR_TO_EXECUTBLE);
		var_oldpwd->ft_dynamic_value = ft_dynamic_value;
	}
}
