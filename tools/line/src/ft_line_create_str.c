/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_create_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 02:47:33 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 19:36:38 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

t_line	*ft_line_create_str(const char *string)
{
	t_line	*result;

	result = ft_line_new(0);
	if (result && !ft_line_cpy_str(result, string))
	{
		ft_line_del(result);
		result = 0;
	}
	return (result);
}
