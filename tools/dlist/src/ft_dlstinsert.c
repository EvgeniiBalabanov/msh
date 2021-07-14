/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstinsert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 01:11:24 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 18:41:47 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_dlstinsert(t_dlist *left, t_dlist *center, t_dlist *right)
{
	ft_dlstrelation(left, center);
	ft_dlstrelation(center, right);
}
