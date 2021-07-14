/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:28:39 by telron            #+#    #+#             */
/*   Updated: 2020/12/17 16:03:47 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

t_dlist	*ft_dlstmap(t_dlist *dlst, void *(*f)(void *), void (*del)(void *))
{
	t_dlist	*result;
	t_dlist	*elem;

	result = 0;
	if (!f)
		return (0);
	while (dlst)
	{
		elem = ft_dlstnew(f(dlst->content));
		if (!elem)
		{
			ft_dlstclear(&result, del);
			return (0);
		}
		ft_dlstadd_right(&result, elem);
		dlst = dlst->right;
	}
	return (result);
}
