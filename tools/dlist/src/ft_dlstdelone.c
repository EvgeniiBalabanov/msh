/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:15:40 by telron            #+#    #+#             */
/*   Updated: 2020/12/07 23:04:28 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_dlstdelone(t_dlist *dlst, void (*del)(void*))
{
	if (dlst)
	{
		if (del)
			del(dlst->content);
		free(dlst);
	}
}
