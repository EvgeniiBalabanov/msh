/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_content.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 04:16:09 by telron            #+#    #+#             */
/*   Updated: 2021/05/30 20:14:48 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*ft_lstadd_front_content(t_list **lst, void *content)
{
	t_list	*new;

	new = ft_lstnew(content);
	if (new)
		ft_lstadd_front(lst, new);
	return (new);
}
