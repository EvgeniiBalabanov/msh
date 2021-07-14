/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_wildcard_recursion_set_path_and_pa        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:13:30 by aberry            #+#    #+#             */
/*   Updated: 2021/06/21 18:31:10 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlen_c(const char *str, const char sep)
{
	size_t	counter;
	size_t	i;

	counter = 0;
	i = 0;
	while (str[counter])
		if (str[counter++] == sep)
			i++;
	return (i);
}

static void	ft_wildcard_check_pattern(t_line **pattern)
{
	if ((*pattern)->string[0] != '/' && ft_strncmp((*pattern)->string, "./", 2))
	{
		ft_line_insert_chr((*pattern), '.', 0);
		ft_line_insert_chr((*pattern), '/', 1);
	}
	if ((*pattern)->string[(*pattern)->length - 1] == '/')
	{
		ft_line_del_chr(*pattern, (*pattern)->length - 1);
	}
}

int	ft_parse_wildcard_recursion_set_path_and_pattern(\
				t_line **path, \
				t_line **pattern)
{
	size_t		offset;
	t_line		*tmp;
	char		*new_pattern;

	tmp = *pattern;
	ft_wildcard_check_pattern(pattern);
	new_pattern = ft_strchr(tmp->string, '*');
	if (!new_pattern)
		return (1);
	while (*new_pattern != '/')
		new_pattern--;
	new_pattern++;
	*pattern = ft_line_create_str(new_pattern);
	offset = new_pattern - tmp->string;
	*path = ft_line_sub_line(tmp, 0, offset);
	ft_line_del(tmp);
	if (!*pattern || !*path)
		return (1);
	return (0);
}
