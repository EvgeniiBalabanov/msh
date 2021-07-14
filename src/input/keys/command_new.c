/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:58:18 by telron            #+#    #+#             */
/*   Updated: 2021/06/09 00:15:22 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inp_keys_command_new(t_shell *config)
{
	size_t	*digit_ptr;
	size_t	save_digit;

	ft_inp_command_new(&config->view);
	digit_ptr = ft_inp_get_mode_digit_ptr(config);
	save_digit = *digit_ptr;
	*digit_ptr = -1;
	ft_inp_keys_command_down(config);
	*digit_ptr = save_digit;
}
