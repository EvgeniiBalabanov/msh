/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_str_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 07:31:40 by telron            #+#    #+#             */
/*   Updated: 2021/06/03 07:58:29 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_test.h"

static void	ft_case_with_str(const char *string_1, const char *string_2)
{
	t_line	*line;
	size_t	len_1;
	size_t	len_2;
	size_t	counter;
	char	*result;

	counter = 0;
	line = ft_line_create_str(string_1);
	len_1 = ft_strlen(string_1);
	len_2 = ft_strlen(string_2);
	result = ft_strjoin(string_1, string_2);
	ft_line_add_str(line, string_2);
	if (!ft_strcmp(line->string, result) && \
		(len_1 + len_2 == line->length) && \
		(line->length < line->allocated))
		ft_putstr_fd("\033[0;32m[OK]\033[0m", 1);
	else
		ft_putstr_fd("\033[0;31m[KO]\033[0m", 2);
	ft_line_del(line);
	free(result);
}

static void	ft_case(const char *string)
{
	ft_putstr_fd("|   ft_line_add_str   | ", 1);
	ft_case_with_str(string, "a");
	ft_case_with_str(string, "b");
	ft_case_with_str(string, "Ad");
	ft_case_with_str(string, "zzz");
	ft_case_with_str(string, "test");
	ft_case_with_str(string, "1234567890qwertyuiopasdfghjkl;zxcvbnm,.");
	ft_case_with_str(string, "blablablablablablablablablablablablablabla");
	ft_case_with_str(string, "blablablablabla      \n\t\v    blabla");
	ft_putstr_fd("\n", 1);
}

void	ft_line_add_str_test(void)
{
	ft_case("a");
	ft_case("b");
	ft_case("Ad");
	ft_case("zzz");
	ft_case("test");
	ft_case("1234567890qwertyuiopasdfghjkl;zxcvbnm,.");
	ft_case("blablablablablablablablablablablablablabla");
	ft_case("blablablablabla      \n\t\v    blabla");
}
