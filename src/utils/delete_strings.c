/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_strings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 20:32:55 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 09:30:16 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_delete_strings(char **strings)
{
	size_t	counter;

	counter = 0;
	while (strings && strings[counter])
	{
		free(strings[counter]);
		counter++;
	}
	free(strings);
}
