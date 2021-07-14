/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 22:07:15 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 01:18:52 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env_var_dv_random(t_shell __attribute__((unused)) *config, \
							t_variable *var_random)
{
	char				buffer[2];
	int					fd;
	unsigned short int	digit;
	char				*value;

	fd = open("/dev/urandom", O_RDONLY);
	if (-1 == fd)
		return ;
	if (-1 != read(fd, buffer, 2))
	{
		digit = ((unsigned short int *)buffer)[0];
		value = ft_itoa((int)digit);
		if (value)
		{
			free(var_random->value);
			var_random->value = value;
		}
	}
	close(fd);
}
