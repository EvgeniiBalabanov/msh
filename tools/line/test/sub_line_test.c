/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_line_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 21:39:27 by telron            #+#    #+#             */
/*   Updated: 2021/06/03 08:00:09 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_test.h"

static void	ft_case(const char *string, size_t start, size_t stop)
{
	t_line	*line_src;
	t_line	*line_res;
	char	*excepted_string;
	size_t	excepted_len;
	size_t	len;

	line_src = ft_line_create_str(string);
	line_res = ft_line_sub_line(line_src, start, stop);
	len = 0;
	if (stop >= start)
		len = stop - start;
	excepted_string = ft_substr(string, (unsigned int)start, len);
	excepted_len = ft_strlen(excepted_string);
	if (!ft_strcmp(line_res->string, excepted_string) && \
		(excepted_len == line_res->length) && \
		(line_res->length < line_res->allocated))
		ft_putstr_fd("\033[0;32m[OK]\033[0m", 1);
	else
		ft_putstr_fd("\033[0;31m[KO]\033[0m", 2);
	ft_line_del(line_src);
	ft_line_del(line_res);
	free(excepted_string);
}

static void	ft_case_add_start_stop(const char *string)
{
	ft_putstr_fd("|   ft_line_sub_line  | ", 1);
	ft_case(string, 0, 0);
	ft_case(string, 0, 1);
	ft_case(string, 0, 10);
	ft_case(string, 0, 10000);
	ft_case(string, 100, 10);
	ft_case(string, -1, 10);
	ft_case(string, 2, 1);
	ft_case(string, 2, 2);
	ft_case(string, 5, 7);
	ft_case(string, 5, 10);
	ft_case(string, 6, 12);
	ft_putstr_fd("\n", 1);
}

void	ft_line_sub_line_test(void)
{
	ft_case_add_start_stop("a");
	ft_case_add_start_stop("b");
	ft_case_add_start_stop("Ad");
	ft_case_add_start_stop("test");
	ft_case_add_start_stop("1234567890qwertyuiopasdfghjkl;zxcvbnm,.");
	ft_case_add_start_stop("blablablablablablablablablablablablablabla");
	ft_case_add_start_stop("blablablablabla      \n\t\v    blabla");
}
