/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiteri_all_right.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 01:36:02 by telron            #+#    #+#             */
/*   Updated: 2020/12/17 16:03:37 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_dlstiteri(t_dlist *dlst, void (*f)(size_t, void *))
{
	ft_dlstiteri_right(ft_dlstleft(dlst), f);
}
