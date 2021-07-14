/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_str_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 01:34:30 by telron            #+#    #+#             */
/*   Updated: 2021/06/03 08:03:15 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_test.h"

static void	ft_case(size_t size, const char *string)
{
	t_line	*line;
	size_t	len;

	line = ft_line_new(size);
	ft_line_cpy_str(line, string);
	len = ft_strlen(string);
	if (!ft_strcmp(line->string, string) && \
		(len == line->length) && \
		(len < line->allocated))
		ft_putstr_fd("\033[0;32m[OK]\033[0m", 1);
	else
		ft_putstr_fd("\033[0;31m[KO]\033[0m", 2);
	ft_line_del(line);
}

void	ft_line_cpy_str_test(void)
{
	ft_putstr_fd("|   ft_line_cpy_str   | ", 1);
	ft_case(0, "");
	ft_case(1, "");
	ft_case(16, "");
	ft_case(0, "test");
	ft_case(4, "test");
	ft_case(5, "test");
	ft_case(6, "test");
	ft_case(16, "test");
	ft_case(128, "test");
	ft_case(0, "blablablablablablabla");
	ft_case(16, "blablablablablablabla");
	ft_case(128, "blablablablablablabla");
	ft_putstr_fd("\n", 1);
}
