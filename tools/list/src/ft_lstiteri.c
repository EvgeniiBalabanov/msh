/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:41:20 by telron            #+#    #+#             */
/*   Updated: 2020/12/17 15:59:48 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lstiteri(t_list *lst, void (*f)(size_t, void *))
{
	size_t	counter;

	counter = 0;
	while (lst)
	{
		f(counter, lst->content);
		lst = lst->next;
		counter++;
	}
}
