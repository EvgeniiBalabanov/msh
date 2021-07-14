/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:15:14 by telron            #+#    #+#             */
/*   Updated: 2021/02/19 23:23:47 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse_immutable_destructor(\
				t_parse_immutable *immutable)
{
	if (immutable)
	{
		ft_line_del(immutable->line);
	}
}
