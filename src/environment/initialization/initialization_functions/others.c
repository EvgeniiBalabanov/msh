/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 21:57:52 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 01:19:29 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env_var_init_others(t_shell __attribute__((unused)) *config, \
				t_dict **environment, const char *import_variable, size_t index)
{
	t_variable			*variable;

	variable = ft_env_var_new(environment, import_variable, index);
	if (variable)
		variable->attributes = VAR_ATTR_TO_EXECUTBLE;
}
