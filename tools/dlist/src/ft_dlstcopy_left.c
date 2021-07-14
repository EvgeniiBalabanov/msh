/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstcopy_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 04:48:47 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 18:40:21 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

t_dlist	*ft_dlstcopy_left(t_dlist *dlist, void (*del)(void *))
{
	t_dlist	*result;

	result = 0;
	while (dlist)
	{
		if (!ft_dlstadd_left_content(&result, dlist->content))
		{
			ft_dlstclear(&result, del);
			return (0);
		}
		dlist = dlist->left;
	}
	return (result);
}
