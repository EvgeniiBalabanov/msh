/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:04:02 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 18:48:02 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int num)
{
	char	arr[15];
	int		counter_arr;
	int		positive;

	counter_arr = 14;
	arr[counter_arr--] = 0;
	positive = -1 + (num >= 0) * 2;
	if (!num)
		arr[counter_arr--] = '0';
	while (num)
	{
		arr[counter_arr--] = num % 10 * positive + '0';
		num /= 10;
	}
	if (positive == -1)
		arr[counter_arr--] = '-';
	return (ft_strdup(arr + counter_arr + 1));
}
