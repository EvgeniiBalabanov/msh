/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:00:24 by telron            #+#    #+#             */
/*   Updated: 2020/12/08 00:19:44 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_dlstadd_left(t_dlist **dlst, t_dlist *new)
{
	t_dlist	*old_elem;

	old_elem = ft_dlstleft(*dlst);
	if (!old_elem)
		*dlst = new;
	else
		old_elem->left = new;
	new->right = old_elem;
}
