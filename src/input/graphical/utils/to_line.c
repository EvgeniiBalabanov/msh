/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:46:45 by aberry            #+#    #+#             */
/*   Updated: 2021/06/25 02:43:09 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_to_line(t_shell *config, int index)
{
	int	move;

	move = config->view.draw.yy_global - index;
	if (move < 0)
		ft_down(&config->view, move * -1);
	if (move > 0)
		ft_up(&config->view, move);
	config->view.draw.yy_global = index;
}
