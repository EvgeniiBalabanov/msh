/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_in_history.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 18:09:59 by aberry            #+#    #+#             */
/*   Updated: 2021/06/07 21:03:58 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** @function ft_find_command_in_history
** Поиск команды в истории введенных команд.
** @рaram Паттерн по которому необходимо найти совпадающие команды в истории.
** @return Двусвязный список с совпадающими вариантами
** @author Aaron Berry
** @version 1.0
*/

static void	ft_add_command_in_coincidence(\
						t_dlist **coincidence, \
						t_dlist *history, \
						t_line *pattern)
{
	char		*history_str;
	t_line		*coincidence_line;

	history_str = ft_strtrim(((t_line *)history->content)->string, " ");
	if (history_str && ft_strnstr(history_str, pattern->string, \
															pattern->length))
	{
		coincidence_line = ft_line_create_str(history_str);
		if (coincidence_line)
			ft_dlstadd_right_content(coincidence, coincidence_line);
	}
	free(history_str);
}

t_dlist
	*ft_find_command_in_history(t_line *pattern, t_dlist *history)
{
	t_dlist		*coincidence;

	coincidence = 0;
	while (history)
	{
		ft_add_command_in_coincidence(&coincidence, history, pattern);
		history = history->right;
	}
	return (coincidence);
}
