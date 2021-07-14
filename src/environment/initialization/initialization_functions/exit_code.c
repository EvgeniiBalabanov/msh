/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 22:07:17 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 01:23:32 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env_var_init_code_exit(\
					t_shell __attribute__((unused)) *config, \
					t_dict **environment, void *ft_dynamic_value)
{
	t_variable	*var_exit;

	var_exit = ft_env_var_new(environment, "?", -1);
	if (var_exit)
	{
		var_exit->attributes = (VAR_ATTR_NOUNSET | VAR_ATTR_ISDYNAMIC);
		var_exit->ft_dynamic_value = ft_dynamic_value;
	}
}
