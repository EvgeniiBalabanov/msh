/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_begin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:38:52 by aberry            #+#    #+#             */
/*   Updated: 2021/06/08 10:15:33 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ft_get_begin_setup(\
							t_shell *config, \
							t_dlist **start, \
							t_dlist **stop)
{
	size_t		counter;

	counter = 0;
	if ((*stop)->right)
	{
		counter++;
		config->view.draw.yy_real++;
		*stop = (*stop)->right;
		ft_inp_command_get(config)->index_down_line = \
						((t_output_line *)(*stop)->content)->index;
	}
	if (counter < config->view.draw.lines && (*start)->left)
	{
		counter++;
		*start = (*start)->left;
		ft_inp_command_get(config)->index_up_line = \
						((t_output_line *)(*start)->content)->index;
	}
	return (counter);
}

void	ft_get_begin(t_shell *config)
{
	t_dlist	*start;
	t_dlist	*stop;
	size_t	counter;
	size_t	old_counter;

	counter = 1;
	start = config->view.draw.middle;
	stop = config->view.draw.middle;
	ft_inp_command_get(config)->index_down_line = \
										((t_output_line *)stop->content)->index;
	ft_inp_command_get(config)->index_up_line = \
									((t_output_line *)start->content)->index;
	config->view.draw.yy_real = 0;
	while (counter < config->view.draw.lines)
	{
		old_counter = counter;
		counter += ft_get_begin_setup(config, &start, &stop);
		if (old_counter == counter)
			break ;
	}
	config->view.draw.lines = counter;
	config->view.draw.begin = start;
}
