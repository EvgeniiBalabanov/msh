/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_line_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 03:43:45 by telron            #+#    #+#             */
/*   Updated: 2021/06/03 08:02:18 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_test.h"

static void	ft_case(const char *string)
{
	t_line	*line_1;
	t_line	*line_2;

	line_1 = ft_line_create_str(string);
	line_2 = ft_line_create_line(line_1);
	if (!ft_strcmp(line_1->string, line_2->string) && \
		(line_1->length == line_2->length) && \
		(line_1->allocated == line_2->allocated))
		ft_putstr_fd("\033[0;32m[OK]\033[0m", 1);
	else
		ft_putstr_fd("\033[0;31m[KO]\033[0m", 2);
	ft_line_del(line_1);
	ft_line_del(line_2);
}

void	ft_line_create_line_test(void)
{
	ft_putstr_fd("| ft_line_create_line | ", 1);
	ft_case("");
	ft_case("a");
	ft_case("b");
	ft_case("Ad");
	ft_case("zzz");
	ft_case("test");
	ft_case("blablablablablablabla");
	ft_case("blablablablablablablablablablablablablabla");
	ft_case("blablablablabla      \n\t\v    blabla");
	ft_putstr_fd("\n", 1);
}
