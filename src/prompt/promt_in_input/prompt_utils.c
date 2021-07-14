/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 18:59:51 by aberry            #+#    #+#             */
/*   Updated: 2021/06/08 11:30:12 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_line	*ft_move_string(t_line *pattern)
{
	char		*offset;
	size_t		index;
	t_line		*content_line;

	content_line = 0;
	content_line = ft_line_create_line(pattern);
	if (!content_line)
		return (0);
	offset = ft_strrchr(content_line->string, '/');
	if (offset)
	{
		index = offset - content_line->string;
		while (index > 0)
		{
			ft_line_del_chr(content_line, 0);
			index--;
		}
		ft_line_del_chr(content_line, 0);
	}
	return (content_line);
}

int	ft_prompt_command_add_to_dlst(t_dlist *tmp_dlst, t_dlist **res)
{
	t_line		*line_add_dlst;

	while (tmp_dlst)
	{
		line_add_dlst = ft_move_string((t_line *)(tmp_dlst->content));
		if (!line_add_dlst)
			return (1);
		if (!ft_dlstadd_right_content(res, line_add_dlst))
		{
			ft_line_del(line_add_dlst);
			return (1);
		}
		tmp_dlst = tmp_dlst->right;
	}
	return (0);
}

t_dlist	*ft_find_command_in_path(char *path, t_line *line)
{
	t_dlist		*tmp_dlst;
	t_line		*tmp_line;

	tmp_dlst = 0;
	tmp_line = ft_line_create_str(path);
	if (!tmp_line)
		return (0);
	if (!ft_line_add_chr(tmp_line, '/'))
	{
		ft_line_del(tmp_line);
		return (tmp_dlst);
	}
	if (!(ft_line_add_line(tmp_line, line)))
	{
		ft_line_del(tmp_line);
		return (tmp_dlst);
	}
	if (!(ft_line_add_chr(tmp_line, '*')))
	{
		ft_line_del(tmp_line);
		return (tmp_dlst);
	}
	tmp_dlst = ft_parse_wildcard(tmp_line);
	ft_line_del(tmp_line);
	return (tmp_dlst);
}
