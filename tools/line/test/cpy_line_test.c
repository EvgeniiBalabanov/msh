/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_line_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 04:51:50 by telron            #+#    #+#             */
/*   Updated: 2021/06/03 08:02:36 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_test.h"

static void	ft_case(const char *string_1, const char *string_2)
{
	t_line	*line_1;
	t_line	*line_2;

	line_1 = ft_line_create_str(string_1);
	line_2 = ft_line_create_str(string_2);
	ft_line_cpy_line(line_1, line_2);
	if (!ft_strcmp(line_1->string, line_2->string) && \
		(line_1->length == line_2->length) && \
		(line_1->allocated > line_1->length) && \
		(line_1->length == ft_strlen(string_2) && \
		line_1->length == ft_strlen(line_1->string)))
		ft_putstr_fd("\033[0;32m[OK]\033[0m", 1);
	else
		ft_putstr_fd("\033[0;31m[KO]\033[0m", 2);
	ft_line_del(line_1);
	ft_line_del(line_2);
}

void	ft_line_cpy_line_test(void)
{
	ft_putstr_fd("|   ft_line_cpy_line  | ", 1);
	ft_case("", "");
	ft_case("", "abc");
	ft_case("", "test");
	ft_case("", "blablablablablablabla");
	ft_case("abc", "");
	ft_case("abc", "abc");
	ft_case("abc", "test");
	ft_case("abc", "blablablablablablabla");
	ft_case("test", "");
	ft_case("test", "abc");
	ft_case("test", "test");
	ft_case("test", "blablablablablablabla");
	ft_case("blablablablablablabla", "");
	ft_case("blablablablablablabla", "abc");
	ft_case("blablablablablablabla", "test");
	ft_case("blablablablablablabla", "blablablablablablabla");
	ft_putstr_fd("\n", 1);
}
