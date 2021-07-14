/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:33:37 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 14:49:41 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_check_args_isdig(t_shell *config, const char *argv)
{
	size_t		counter;
	long long	result;
	long long	last_result;

	counter = 0;
	result = 0;
	last_result = 0;
	while (argv[counter])
	{
		if (ft_isdigit(argv[counter]))
			result = result * 10 + (argv[counter] - '0');
		if (!(ft_isdigit(argv[counter]) || \
			(counter == 0 && argv[counter] == '-')) || \
			result < last_result)
		{
			ft_error_print(config, "ft_builtin_exit", \
				"exit", "numeric argument required");
			return (-1);
		}
		last_result = result;
		counter++;
	}
	return (ft_atoi(argv));
}

int	ft_builtin_exit(t_shell *config, const char *argv[])
{
	if (config->view.mode != MODE_SCRIPT)
		ft_putendl_fd("exit", 1);
	if (argv[1])
	{
		if (argv[2])
		{
			ft_error_print(config, "ft_builtin_exit", \
				"exit", "too many arguments");
			return (1);
		}
		config->exit_code = ft_check_args_isdig(config, argv[1]);
	}
	ft_exit(config);
	return (0);
}
