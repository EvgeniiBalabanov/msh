/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcard_find_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:12:41 by aberry            #+#    #+#             */
/*   Updated: 2021/06/21 18:47:22 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_offset_if_has_name(\
						char *part_pattern, \
						char *name, \
						size_t *offset)
{
	int		len_part_pattern;
	int		len_name;

	len_name = ft_strlen(name);
	len_part_pattern = ft_strlen(part_pattern);
	name = ft_strnstr(name, part_pattern, len_name);
	if (name)
	{
		*offset = -1;
		if (!ft_strncmp(name, part_pattern, len_part_pattern + 1))
			*offset = len_part_pattern;
	}
}

static int	ft_wildcard_check_name(\
						char **parts_pttrn, \
						char *name, \
						char *pattern, \
						size_t i)
{
	int		start;
	int		end;
	size_t	offset;

	start = (pattern[0] == '*');
	end = (pattern[ft_strlen(pattern) - 1] == '*');
	while (parts_pttrn[i] && *name)
	{
		offset = 0;
		if (i == 0 && !start)
		{
			offset = -1;
			if (!ft_strncmp(name, parts_pttrn[i], ft_strlen(parts_pttrn[i])))
				offset = ft_strlen(parts_pttrn[i]);
		}
		if (!parts_pttrn[i + 1] && !end)
			set_offset_if_has_name(parts_pttrn[i], name, &offset);
		if (!offset && name)
			name = ft_strnstr(name, parts_pttrn[i], ft_strlen(name));
		if (offset == (size_t)(-1) || !name)
			return (0);
		name += offset;
		i++;
	}
	return (1);
}

int	ft_wildcard_find_str(\
				char **parts_pttrn, \
				char *name, \
				char *pattern)
{
	size_t	i;

	if ((!ft_strchr(pattern, '.') && name[0] == '.') || !ft_strcmp(name, ".") \
													|| !ft_strcmp(name, ".."))
		return (0);
	if (!ft_strcmp(pattern, "*"))
		return (1);
	i = 0;
	return (ft_wildcard_check_name(parts_pttrn, name, pattern, i));
}
