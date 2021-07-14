/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_left_content.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 04:56:20 by telron            #+#    #+#             */
/*   Updated: 2020/12/17 16:02:56 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

t_dlist	*ft_dlstadd_left_content(t_dlist **dlst, void *content)
{
	t_dlist	*old_elem;
	t_dlist	*new;

	new = ft_dlstnew(content);
	if (new)
	{
		old_elem = ft_dlstleft(*dlst);
		if (!old_elem)
			*dlst = new;
		else
			old_elem->left = new;
		new->right = old_elem;
	}
	return (new);
}
