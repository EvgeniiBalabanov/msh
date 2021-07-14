/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_str_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 03:12:47 by telron            #+#    #+#             */
/*   Updated: 2021/06/03 08:02:53 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_test.h"

static void	ft_case(const char *string)
{
	t_line	*line;
	size_t	len;

	line = ft_line_create_str(string);
	len = ft_strlen(string);
	if (!ft_strcmp(line->string, string) && \
		(len == line->length) && \
		(len < line->allocated))
		ft_putstr_fd("\033[0;32m[OK]\033[0m", 1);
	else
		ft_putstr_fd("\033[0;31m[KO]\033[0m", 2);
	ft_line_del(line);
}

void	ft_line_create_str_test(void)
{
	ft_putstr_fd("|  ft_line_create_str | ", 1);
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
