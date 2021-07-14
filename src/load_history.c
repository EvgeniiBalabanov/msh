/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 23:55:35 by telron            #+#    #+#             */
/*   Updated: 2021/06/10 12:28:06 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_feal_command(t_shell *config, int fd)
{
	char	buffer;

	while (0 < read(fd, &buffer, 1))
	{
		if (buffer == '\n')
			ft_inp_keys_cursor_down_or_nl(config);
		else
			ft_inp_keys_any_key(config, buffer);
	}
}

static void	ft_create_command(t_shell *config, t_dlist *files)
{
	t_line	*path;
	int		fd;

	while (files)
	{
		path = ft_line_create_str(PATH_HISTORY);
		ft_line_add_str(path, files->content);
		fd = open(path->string, O_RDONLY);
		if (fd > 0)
		{
			ft_inp_keys_command_new(config);
			ft_feal_command(config, fd);
			close(fd);
		}
		ft_line_del(path);
		files = files->right;
	}
}

static int	ft_filename_cmp(const char *str1, const char *str2)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (len1 != len2)
		return (len1 - len2);
	return (ft_strcmp(str1, str2));
}

void	ft_load_history(t_shell *config)
{
	DIR				*dir;
	struct dirent	*ent;
	t_dlist			*files;

	dir = opendir(PATH_HISTORY);
	if (!dir)
		return ;
	files = 0;
	while (1)
	{
		ent = readdir(dir);
		if (!ent)
			break ;
		if (!ft_strcmp(ent->d_name, ".") || !ft_strcmp(ent->d_name, ".."))
			continue ;
		ft_dlstadd_sort(&files, ft_dlstnew(ft_strdup(ent->d_name)), \
			(int (*)(void *, void *))ft_filename_cmp);
	}
	closedir(dir);
	files = ft_dlstleft(files);
	ft_create_command(config, files);
	ft_dlstclear(&files, free);
}
