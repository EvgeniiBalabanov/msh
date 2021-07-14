/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_chr_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 06:58:14 by telron            #+#    #+#             */
/*   Updated: 2021/06/03 08:00:49 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_test.h"

static void	ft_case_with_len(size_t start_size, const char *string)
{
	t_line	*line;
	size_t	len;
	size_t	counter;

	counter = 0;
	line = ft_line_new(start_size);
	len = ft_strlen(string);
	while (string[counter])
	{
		ft_line_add_chr(line, string[counter]);
		counter++;
	}
	if (!ft_strcmp(line->string, string) && \
		(len == line->length) && (len < line->allocated))
		ft_putstr_fd("\033[0;32m[OK]\033[0m", 1);
	else
		ft_putstr_fd("\033[0;31m[KO]\033[0m", 2);
	ft_line_del(line);
}

static void	ft_case(const char *string)
{
	ft_putstr_fd("|   ft_line_add_chr   | ", 1);
	ft_case_with_len(0, string);
	ft_case_with_len(1, string);
	ft_case_with_len(2, string);
	ft_case_with_len(15, string);
	ft_case_with_len(16, string);
	ft_case_with_len(100, string);
	ft_putstr_fd("\n", 1);
}

void	ft_line_add_chr_test(void)
{
	ft_case("a");
	ft_case("b");
	ft_case("Ad");
	ft_case("zzz");
	ft_case("test");
	ft_case("blablablablablablabla");
	ft_case("blablablablablablablablablablablablablabla");
	ft_case("blablablablabla      \n\t\v    blabla");
}
