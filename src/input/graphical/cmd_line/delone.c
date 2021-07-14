/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 19:44:32 by telron            #+#    #+#             */
/*   Updated: 2021/06/08 10:15:33 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inp_cmd_line_delone(t_cmd_line *cmd_line)
{
	ft_line_del(cmd_line->line);
	free(cmd_line);
}
