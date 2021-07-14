/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_chr_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 02:13:54 by telron            #+#    #+#             */
/*   Updated: 2021/06/03 07:59:03 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_test.h"

static void	ft_case(size_t size, char chr)
{
	t_line	*line;
	size_t	len;
	char	buf[2];

	line = ft_line_new(size);
	ft_line_cpy_chr(line, chr);
	buf[0] = chr;
	buf[1] = 0;
	len = ft_strlen(buf);
	if (!ft_strcmp(line->string, buf) && \
		(len == line->length) && \
		(len < line->allocated))
		ft_putstr_fd("\033[0;32m[OK]\033[0m", 1);
	else
		ft_putstr_fd("\033[0;31m[KO]\033[0m", 2);
	ft_line_del(line);
}

void	ft_line_cpy_chr_test(void)
{
	ft_putstr_fd("|   ft_line_cpy_chr   | ", 1);
	ft_case(0, '\0');
	ft_case(1, '\0');
	ft_case(16, '\0');
	ft_case(0, 'a');
	ft_case(1, 'b');
	ft_case(2, 'c');
	ft_case(16, 'd');
	ft_case(128, 'e');
	ft_putstr_fd("\n", 1);
}
