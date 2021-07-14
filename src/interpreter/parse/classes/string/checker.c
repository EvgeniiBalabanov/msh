/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:14:08 by telron            #+#    #+#             */
/*   Updated: 2021/04/24 18:25:55 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse_string_checker(t_parse_string *string)
{
	if (string)
	{
		ft_putstr_fd("String(", 1);
		ft_putstr_fd(string->line->string, 1);
		ft_putstr_fd(")", 1);
	}
}
