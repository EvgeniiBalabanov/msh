/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 00:40:43 by telron            #+#    #+#             */
/*   Updated: 2020/12/08 00:50:04 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_dlstclear(t_dlist **dlst, void (*del)(void*))
{
	t_dlist	*buf;

	if (dlst && *dlst)
	{
		buf = ft_dlstleft(*dlst);
		ft_dlstclear_right(&buf, del);
	}
	*dlst = 0;
}
