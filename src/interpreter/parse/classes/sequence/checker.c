/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 01:39:15 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 09:32:28 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_func(\
					size_t index, \
					void *element)
{
	ft_putstr_fd("\t[", 1);
	ft_putnbr_fd(index, 1);
	ft_putstr_fd("]{", 1);
	ft_parse_element_checker(element);
	ft_putstr_fd("}\n", 1);
}

void	ft_parse_sequence_checker(t_parse_sequence *sequence)
{
	if (sequence)
	{
		ft_putstr_fd("Sequence(\n", 1);
		ft_dlstiteri(sequence->dlist_element, ft_func);
		ft_putstr_fd(")", 1);
	}
}
