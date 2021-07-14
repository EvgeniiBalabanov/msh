/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:15:14 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 10:03:59 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse_pipe_destructor(t_parse_pipe *pipe)
{
	if (pipe)
	{
		ft_parse_element_destructor(pipe->left);
		ft_parse_element_destructor(pipe->right);
	}
}
