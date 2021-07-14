/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:40:09 by telron            #+#    #+#             */
/*   Updated: 2021/06/28 03:29:11 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

inline void	ft_up(t_view *view, int count)
{
	while (count--)
		write(view->fd_dev_tty, "\033[A", 3);
}

inline void	ft_down(t_view *view, int count)
{
	while (count--)
		write(view->fd_dev_tty, "\033[B", 3);
}

inline void	ft_right(t_view *view, int count)
{
	while (count--)
		write(view->fd_dev_tty, "\033[C", 3);
}

inline void	ft_put_n(t_view *view, int count)
{
	while (count--)
		write(view->fd_dev_tty, "\n", 1);
}
