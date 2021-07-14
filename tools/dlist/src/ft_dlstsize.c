/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:04:34 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 18:42:07 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

int	ft_dlstsize(t_dlist *dlst)
{
	int	result;

	result = 0;
	if (dlst)
	{
		result++;
		result += ft_dlstsize_left(dlst->left);
		result += ft_dlstsize_right(dlst->right);
	}
	return (result);
}
