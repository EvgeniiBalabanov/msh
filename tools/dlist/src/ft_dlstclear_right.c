/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:18:40 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 18:39:12 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_dlstclear_right(t_dlist **dlst, void (*del)(void*))
{
	t_dlist	*buf;

	while (dlst && *dlst)
	{
		if ((*dlst)->left)
			(*dlst)->left = 0;
		buf = (*dlst)->right;
		ft_dlstdelone(*dlst, del);
		*dlst = buf;
	}
	*dlst = 0;
}
