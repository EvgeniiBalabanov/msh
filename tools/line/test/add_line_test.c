/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_line_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 07:49:25 by telron            #+#    #+#             */
/*   Updated: 2021/06/03 08:00:38 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_test.h"

static void	ft_case_with_line(const char *string_1, const char *string_2)
{
	t_line	*line_1;
	t_line	*line_2;
	size_t	len_1;
	size_t	len_2;
	char	*result;

	line_1 = ft_line_create_str(string_1);
	line_2 = ft_line_create_str(string_2);
	len_1 = ft_strlen(string_1);
	len_2 = ft_strlen(string_2);
	result = ft_strjoin(string_1, string_2);
	ft_line_add_line(line_1, line_2);
	if (!ft_strcmp(line_1->string, result) && \
		(len_1 + len_2 == line_1->length) && \
		(line_1->length < line_1->allocated))
		ft_putstr_fd("\033[0;32m[OK]\033[0m", 1);
	else
		ft_putstr_fd("\033[0;31m[KO]\033[0m", 2);
	ft_line_del(line_1);
	ft_line_del(line_2);
	free(result);
}

static void	ft_case(const char *string)
{
	ft_putstr_fd("|   ft_line_add_line  | ", 1);
	ft_case_with_line(string, "a");
	ft_case_with_line(string, "b");
	ft_case_with_line(string, "Ad");
	ft_case_with_line(string, "zzz");
	ft_case_with_line(string, "test");
	ft_case_with_line(string, "1234567890qwertyuiopasdfghjkl;zxcvbnm,.");
	ft_case_with_line(string, "blablablablablablablablablablablablablabla");
	ft_case_with_line(string, "blablablablabla      \n\t\v    blabla");
	ft_putstr_fd("\n", 1);
}

void	ft_line_add_line_test(void)
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
