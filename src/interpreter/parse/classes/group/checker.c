/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:14:08 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 10:00:58 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse_group_checker(t_parse_group *group)
{
	if (group)
	{
		ft_putstr_fd("Group(", 1);
		ft_parse_element_checker(group->element);
		ft_putstr_fd(")", 1);
	}
}
