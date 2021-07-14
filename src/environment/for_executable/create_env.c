/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 12:14:03 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 05:18:38 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**ft_get_result(t_list *list)
{
	char		**result;
	size_t		counter;
	size_t		count;

	count = ft_lstsize(list);
	result = (char **)ft_calloc(count + 1, sizeof(char *));
	counter = 0;
	while (result && list && counter < count)
	{
		result[counter++] = list->content;
		list = list->next;
	}
	return (result);
}

char	**ft_env_create_env(t_shell *config)
{
	t_list		*list_vars;
	t_variable	*variable;
	char		**result;

	list_vars = 0;
	while (ft_dict_iter_value(config->environment, (void **)&variable))
	{
		if (!(variable->attributes & VAR_ATTR_TO_EXECUTBLE) || \
			(variable->attributes & VAR_ATTR_INVISIBLE))
			continue ;
		if (variable->attributes & VAR_ATTR_ISDYNAMIC)
			((t_ft_dyn_var)variable->ft_dynamic_value)(config, variable);
		if (variable->value_for_exe)
			ft_lstadd_back_content(&list_vars, variable->value_for_exe);
	}
	result = ft_get_result(list_vars);
	ft_lstclear(&list_vars, 0);
	return (result);
}
