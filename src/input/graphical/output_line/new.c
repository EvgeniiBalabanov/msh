/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 12:04:39 by telron            #+#    #+#             */
/*   Updated: 2021/06/08 10:15:33 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_output_line	*ft_inp_output_line_new(\
							t_line *line, \
							size_t index, \
							size_t start, \
							size_t stop)
{
	t_output_line	*result;

	result = (t_output_line *)ft_calloc(sizeof(t_output_line), 1);
	if (result)
	{
		result->line = line;
		result->is_first_line = !start;
		result->index = index;
		result->start = start;
		result->stop = stop;
	}
	return (result);
}
