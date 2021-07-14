/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 00:00:21 by telron            #+#    #+#             */
/*   Updated: 2021/06/09 00:20:03 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_create_command_for_view_command(t_view *view)
{
	if (!view->command)
	{
		ft_inp_command_new(view);
		view->index_command++;
	}
}

static void	ft_dlst_has_left(t_view *view, t_dlist *dlist, \
							size_t *count_command)
{
	view->command = dlist->left->content;
	view->index_command--;
	*count_command = 0;
}

static void	ft_dlst_is_empty(t_view *view)
{
	view->command = 0;
	view->index_command--;
}

void	ft_inp_keys_command_delete(t_shell *config)
{
	t_dlist		*dlist;
	size_t		count_command;
	t_view		*view;

	view = &config->view;
	dlist = &view->command->transport;
	count_command = ft_inp_get_mode_digit(config, 1);
	while (dlist && count_command--)
	{
		if (dlist->right)
			view->command = dlist->right->content;
		else if (dlist->left)
			ft_dlst_has_left(view, dlist, &count_command);
		else
			ft_dlst_is_empty(view);
		ft_dlstrelation(dlist->left, dlist->right);
		ft_inp_command_delone(dlist->content);
		view->count_command--;
		dlist = &view->command->transport;
	}
	ft_create_command_for_view_command(view);
}
