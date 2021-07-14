/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 02:42:26 by telron            #+#    #+#             */
/*   Updated: 2021/06/03 08:01:19 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_test.h"

static void	ft_case(char chr)
{
	t_line	*line;
	size_t	len;
	char	buf[2];

	line = ft_line_create_chr(chr);
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

void	ft_line_create_chr_test(void)
{
	ft_putstr_fd("|  ft_line_create_chr | ", 1);
	ft_case('\0');
	ft_case('\0');
	ft_case('\0');
	ft_case('a');
	ft_case('b');
	ft_case('c');
	ft_case('d');
	ft_case('e');
	ft_putstr_fd("\n", 1);
}
