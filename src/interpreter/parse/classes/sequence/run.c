/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:15:31 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 09:32:04 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse_sequence_run(\
					t_shell *config, \
					t_stream *stream, \
					t_parse_sequence *sequence)
{
	t_dlist	*dlist;

	dlist = sequence->dlist_element;
	while (dlist)
	{
		ft_parse_element_run(config, stream, dlist->content);
		dlist = dlist->right;
	}
}
