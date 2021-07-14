/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:15:31 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 09:33:24 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse_or_run(\
					t_shell *config, \
					t_stream *stream, \
					t_parse_or *element)
{
	if (stream->exit_code)
		ft_parse_element_run(config, stream, element->element);
}
