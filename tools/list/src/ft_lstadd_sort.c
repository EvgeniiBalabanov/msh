/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 03:49:08 by telron            #+#    #+#             */
/*   Updated: 2020/12/17 16:00:01 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lstadd_sort(t_list **lst, t_list *new, int (*f)(void *, void *))
{
	t_list	*buf;
	t_list	*last;

	if (!lst || !new)
		return ;
	buf = *lst;
	last = 0;
	while (buf && 0 < f(buf->content, new->content))
	{
		last = buf;
		buf = buf->next;
	}
	if (last)
		last->next = new;
	else
		*lst = new;
	new->next = buf;
}
