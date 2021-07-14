/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter_all_left.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 23:51:33 by telron            #+#    #+#             */
/*   Updated: 2020/12/17 16:03:27 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_dlstiter_all_left(t_dlist *dlst, void (*f)(void *))
{
	ft_dlstiter_left(ft_dlstright(dlst), f);
}
