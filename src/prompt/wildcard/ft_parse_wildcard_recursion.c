/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_wildcard_recursion.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:10:20 by aberry            #+#    #+#             */
/*   Updated: 2021/06/24 01:57:47 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_line	*ft_wildcard_create_line(\
					t_line *path, \
					struct dirent *entry, \
					t_line *pattern, \
					t_line *origin_pattern)
{
	t_line			*tmp;

	tmp = ft_line_create_line(path);
	if (!tmp)
		return (0);
	if (!ft_line_add_str(tmp, entry->d_name))
		return (0);
	if ((int)ft_strlen_c(path->string, '/') == ft_wildcard_step(origin_pattern))
	{
		if (origin_pattern->string[origin_pattern->length - 1] == '/')
			if (!ft_line_add_chr(tmp, '/'))
				return (0);
		if (!ft_strncmp(tmp->string, "./", 2) && \
			ft_strncmp(origin_pattern->string, "./", 2))
		{
			ft_line_del_chr(tmp, 0);
			ft_line_del_chr(tmp, 0);
		}
	}
	else if (!ft_line_add_line(tmp, pattern))
		return (0);
	return (tmp);
}

static char	**ft_(t_dir *dr, t_line *path, t_line *pat, t_line **pat_tmp)
{
	char	**pat_arr;

	dr->dir = opendir(path->string);
	if (!dr->dir)
		return (0);
	pat_arr = ft_wildcard_set_pattern_array(pat, pat_tmp);
	if (!pat_arr)
		closedir(dr->dir);
	return (pat_arr);
}

int	ft_parse_wildcard_recursion(\
				t_dlist **res, \
				t_line *pat, \
				t_line *org_pat)
{
	t_line	*path;
	t_line	*pat_tmp;
	t_line	*tmp;
	t_dir	dr;
	char	**pat_arr;

	ft_init_variable(&path, &pat_arr, &pat_tmp);
	if (ft_parse_wildcard_recursion_set_path_and_pattern(&path, &pat))
		return (ft_ret(path, pat, pat_tmp, pat_arr));
	pat_arr = ft_(&dr, path, pat, &pat_tmp);
	if (!pat_arr)
		return (ft_ret(path, pat, pat_tmp, pat_arr));
	dr.entry = readdir(dr.dir);
	while (dr.entry)
	{
		if (ft_wildcard_find_str(pat_arr, dr.entry->d_name, pat_tmp->string))
		{
			tmp = ft_wildcard_create_line(path, dr.entry, pat, org_pat);
			if (!tmp || ft_add_or_recursion(res, path, tmp, org_pat))
				return (ft_ret(path, pat, pat_tmp, pat_arr) + closedir(dr.dir));
		}
		dr.entry = readdir(dr.dir);
	}
	ft_ret(path, pat, pat_tmp, pat_arr);
	return (closedir(dr.dir));
}
