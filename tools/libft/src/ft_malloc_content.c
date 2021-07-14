/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:01:50 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 19:07:10 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc_content(void *content, size_t size)
{
	void	*new;

	new = malloc(size);
	if (new)
		ft_memcpy(new, content, size);
	return (new);
}
