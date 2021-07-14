/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:15:14 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 09:36:39 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse_element_destructor(\
					t_parse_element *element)
{
	if (element)
	{
		((void (*)(void *))element->destructor)(&element->content);
		free(element);
	}
}
