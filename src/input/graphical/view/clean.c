/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:52:57 by telron            #+#    #+#             */
/*   Updated: 2021/06/28 03:29:11 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inp_view_clean(t_view *view)
{
	ft_down(view, view->draw.yy_real);
	write(view->fd_dev_tty, "\r", 1);
	ft_up(view, view->draw.lines);
	write(view->fd_dev_tty, "\033[0J\r", 5);
	ft_down(view, view->draw.lines);
}
