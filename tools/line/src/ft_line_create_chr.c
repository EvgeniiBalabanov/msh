/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_create_chr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 02:35:21 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 19:32:06 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

t_line	*ft_line_create_chr(char chr)
{
	t_line	*result;

	result = ft_line_new(16);
	if (result)
		ft_line_cpy_chr(result, chr);
	return (result);
}
