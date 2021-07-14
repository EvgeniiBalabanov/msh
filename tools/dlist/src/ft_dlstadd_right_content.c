/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_right_content.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:05:02 by telron            #+#    #+#             */
/*   Updated: 2020/12/17 16:03:02 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

t_dlist	*ft_dlstadd_right_content(t_dlist **dlst, void *content)
{
	t_dlist	*old_elem;
	t_dlist	*new;

	new = ft_dlstnew(content);
	if (new)
	{
		old_elem = ft_dlstright(*dlst);
		if (!old_elem)
			*dlst = new;
		else
			old_elem->right = new;
		new->left = old_elem;
	}
	return (new);
}
