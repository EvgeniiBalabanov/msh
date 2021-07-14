/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 21:27:10 by aberry            #+#    #+#             */
/*   Updated: 2021/06/29 11:46:18 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_builtin_pwd(t_shell *config, const char __attribute__((unused)) *argv[])
{
	char	*pwd;

	pwd = ft_env_var_get_by_system(config, "PWD");
	if (pwd)
	{
		ft_putstr_fd(pwd, 1);
		ft_putchar_fd('\n', 1);
	}
	else
	{
		ft_error_print(config, "pwd", "not found", \
			"PWD variable not exist or getcwd error");
		return (12);
	}
	return (0);
}
