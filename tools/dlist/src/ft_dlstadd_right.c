/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:11:31 by telron            #+#    #+#             */
/*   Updated: 2020/12/08 00:11:04 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_dlstadd_right(t_dlist **dlst, t_dlist *new)
{
	t_dlist	*old_elem;

	old_elem = ft_dlstright(*dlst);
	if (!old_elem)
		*dlst = new;
	else
		old_elem->right = new;
	new->left = old_elem;
}
