/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiteri_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:41:20 by telron            #+#    #+#             */
/*   Updated: 2020/12/17 16:03:40 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_dlstiteri_right(t_dlist *dlst, void (*f)(size_t, void *))
{
	size_t	counter;

	counter = 0;
	while (dlst)
	{
		f(counter, dlst->content);
		dlst = dlst->right;
		counter++;
	}
}
