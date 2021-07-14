/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 21:27:03 by aberry            #+#    #+#             */
/*   Updated: 2021/06/07 14:43:01 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_is_argum_n(const char *argum)
{
	size_t	counter;

	counter = 0;
	if (argum[counter++] != '-')
		return (0);
	while (argum[counter] == 'n')
		counter++;
	return (!argum[counter] && counter >= 2);
}

int	ft_builtin_echo(\
				t_shell __attribute__((unused)) *config, \
				const char *argv[])
{
	int		counter;
	int		flag;

	counter = 1;
	flag = 1;
	while (argv[counter] && ft_is_argum_n(argv[counter]))
	{
		flag = 0;
		if (argv[counter++][2])
			break ;
	}
	while (argv[counter])
	{
		ft_putstr_fd(argv[counter], 1);
		if (argv[counter + 1])
			ft_putchar_fd(' ', 1);
		counter++;
	}
	if (flag)
		ft_putchar_fd('\n', 1);
	return (0);
}
