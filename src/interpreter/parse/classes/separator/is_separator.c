/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_separator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 03:05:36 by telron            #+#    #+#             */
/*   Updated: 2021/06/21 03:43:08 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parse_separator_is(t_parse_element *element, const char *string)
{
	return (element->type == SEPARATOR_CODE && \
		!ft_strcmp(element->content.separator.line->string, string));
}
