/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_content.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:05:02 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 20:14:39 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*ft_lstadd_back_content(t_list **lst, void *content)
{
	t_list	*last;
	t_list	*new;

	new = ft_lstnew(content);
	if (new)
	{
		last = ft_lstlast(*lst);
		if (!last)
			*lst = new;
		else
			last->next = new;
	}
	return (new);
}
