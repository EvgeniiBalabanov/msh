/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:15:14 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 09:39:08 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse_redirection_destructor(t_parse_redirection *redirection)
{
	if (redirection)
	{
		ft_parse_element_destructor(redirection->element);
		ft_dlstclear(&redirection->name_file, \
			(void (*)(void *))ft_parse_element_destructor);
	}
}
