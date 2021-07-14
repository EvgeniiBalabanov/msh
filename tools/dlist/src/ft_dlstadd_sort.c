/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 03:49:08 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 18:43:29 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

static void	ft_dlstadd_sorted(t_dlist **begin, t_dlist *new, \
								int (*f)(void *, void *))
{
	t_dlist	*dlst;

	dlst = *begin;
	while (dlst && dlst->left)
	{
		if (f(dlst->content, new->content) < 0)
			break ;
		dlst = dlst->left;
	}
	while (dlst && dlst->right)
	{
		if (f(dlst->content, new->content) > 0)
			break ;
		dlst = dlst->right;
	}
	if (f(dlst->content, new->content) < 0)
		ft_dlstinsert(dlst, new, dlst->right);
	else
		ft_dlstinsert(dlst->left, new, dlst);
}

void	ft_dlstadd_sort(t_dlist **dlst, \
						t_dlist *new, int (*f)(void *, void *))
{
	if (!dlst || !new || !f)
		return ;
	if (!*dlst)
		*dlst = new;
	else
		ft_dlstadd_sorted(dlst, new, f);
}
