/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:25:16 by telron            #+#    #+#             */
/*   Updated: 2020/12/07 23:55:54 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_dlstiter_right(t_dlist *dlst, void (*f)(void *))
{
	while (dlst)
	{
		f(dlst->content);
		dlst = dlst->right;
	}
}
