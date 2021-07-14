/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter_all_right.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 23:49:02 by telron            #+#    #+#             */
/*   Updated: 2020/12/07 23:56:38 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_dlstiter_all_right(t_dlist *dlst, void (*f)(void *))
{
	ft_dlstiter_right(ft_dlstleft(dlst), f);
}
