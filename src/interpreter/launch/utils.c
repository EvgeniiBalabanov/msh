/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 23:56:32 by telron            #+#    #+#             */
/*   Updated: 2021/06/09 23:56:53 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_reload_fd(t_descriptors *fd_saved)
{
	dup2(fd_saved->std_in, 0);
	dup2(fd_saved->std_out, 1);
	dup2(fd_saved->std_err, 2);
	close(fd_saved->std_in);
	close(fd_saved->std_out);
	close(fd_saved->std_err);
}

void	ft_dup_fd(t_descriptors *fd_saved, t_executable *executable)
{
	fd_saved->std_in = dup(0);
	fd_saved->std_out = dup(1);
	fd_saved->std_err = dup(2);
	dup2(executable->descriptors.std_in, 0);
	dup2(executable->descriptors.std_out, 1);
	dup2(executable->descriptors.std_err, 2);
}
