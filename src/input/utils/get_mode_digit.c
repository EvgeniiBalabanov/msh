/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mode_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:37:39 by telron            #+#    #+#             */
/*   Updated: 2021/06/08 23:56:18 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_inp_get_mode_digit(t_shell *config, size_t min)
{
	size_t	digit;

	if (config->view.mode & MODE_CHOICE)
		digit = config->view.mode_choice.digit_for_normal;
	else if (config->view.mode & MODE_NOTE)
		digit = config->view.mode_note.digit_for_normal;
	else
		digit = config->view.mode_normal.digit_for_normal;
	if (min > digit)
		digit = min;
	return (digit);
}

size_t	*ft_inp_get_mode_digit_ptr(t_shell *config)
{
	if (config->view.mode & MODE_CHOICE)
		return (&config->view.mode_choice.digit_for_normal);
	else if (config->view.mode & MODE_NOTE)
		return (&config->view.mode_note.digit_for_normal);
	return (&config->view.mode_normal.digit_for_normal);
}
