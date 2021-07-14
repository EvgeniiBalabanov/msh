/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 23:47:27 by telron            #+#    #+#             */
/*   Updated: 2020/12/17 16:03:32 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_dlstiter_left(t_dlist *dlst, void (*f)(void *))
{
	while (dlst)
	{
		f(dlst->content);
		dlst = dlst->left;
	}
}
