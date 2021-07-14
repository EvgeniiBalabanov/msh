/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 01:02:39 by telron            #+#    #+#             */
/*   Updated: 2021/06/03 08:01:30 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_test.h"

static void	ft_case(size_t size)
{
	t_line	*line;

	line = ft_line_new(size);
	if (line->allocated == size && line->length == 0)
		ft_putstr_fd("\033[0;32m[OK]\033[0m", 1);
	else
		ft_putstr_fd("\033[0;31m[KO]\033[0m", 2);
	ft_line_del(line);
}

void	ft_line_new_test(void)
{
	ft_putstr_fd("|     ft_line_new     | ", 1);
	ft_case(0);
	ft_case(1);
	ft_case(16);
	ft_case(1000);
	ft_putstr_fd("\n", 1);
}
