/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 20:58:15 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 14:39:09 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_write_line(t_cmd_line *cmd_line, int fd)
{
	write(fd, cmd_line->line->string, cmd_line->line->length);
}

static void	ft_save_command(size_t index, t_command *command)
{
	t_line		*path;
	char		*str_index;
	int			fd;
	t_dlist		*dlst_line;

	if (!ft_command_length(command))
		return ;
	path = ft_line_create_str(PATH_HISTORY);
	str_index = ft_itoa((int)index);
	ft_line_add_str(path, str_index);
	ft_line_add_str(path, ".sh");
	fd = open(path->string, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dlst_line = ft_dlstleft(&command->cmd_line->transport);
	while (fd > 0 && dlst_line)
	{
		ft_write_line((t_cmd_line *)dlst_line->content, fd);
		if (dlst_line->right)
			write(fd, "\n", 1);
		dlst_line = dlst_line->right;
	}
	free(str_index);
	ft_line_del(path);
	close(fd);
}

void	ft_save_history(t_shell *config)
{
	DIR				*dir;
	struct dirent	*ent;
	t_line			*path;

	dir = opendir(PATH_HISTORY);
	if (!dir)
		return ;
	while (1)
	{
		ent = readdir(dir);
		if (!ent)
			break ;
		if (!ft_strcmp(ent->d_name, ".") || !ft_strcmp(ent->d_name, ".."))
			continue ;
		path = ft_line_create_str(PATH_HISTORY);
		ft_line_add_str(path, ent->d_name);
		remove(path->string);
	}
	closedir(dir);
	if (config->view.command)
		ft_dlstiteri(&config->view.command->transport, \
			(void (*)(size_t, void *))ft_save_command);
}
