/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:15:31 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 09:49:46 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_error_handler(\
						t_shell *config, \
						t_stream *stream, \
						t_line *name_file, \
						int type)
{
	if (type == 1)
	{
		ft_error_print(config, "ft_parse_redirection_run", \
										name_file->string, "Permission denied");
		stream->exit_code = 1;
	}
	ft_line_del(name_file);
	return ;
}

static t_line	*ft_get_file_name(\
						t_shell *config, \
						t_dlist *file_name_dlist)
{
	t_line			*line;
	t_parse_element	*element;
	char			*variable_value;

	line = ft_line_create_str("");
	while (file_name_dlist)
	{
		element = (t_parse_element *)file_name_dlist->content;
		if (element->type == STRING_CODE)
			ft_line_add_line(line, element->content.string.line);
		else if (element->type == IMMUTABLE_CODE)
			ft_line_add_line(line, element->content.immutable.line);
		else if (element->type == VARIABLE_CODE)
		{
			variable_value = ft_env_var_get_by_user(config, \
									element->content.variable.line->string);
			if (variable_value)
				ft_line_add_str(line, variable_value);
		}
		file_name_dlist = file_name_dlist->right;
	}
	return (line);
}

void	ft_parse_redirection_run(\
					t_shell *config, \
					t_stream *stream, \
						t_parse_redirection *redirection)
{
	t_line		*name_file;
	int			save_fd;
	int			*ptr_fd;
	static int	flags[] = {O_WRONLY | O_CREAT | O_APPEND, \
				O_WRONLY | O_CREAT | O_TRUNC, O_RDONLY};

	name_file = ft_get_file_name(config, redirection->name_file);
	ptr_fd = &stream->descriptors.std_out;
	if (redirection->type == 3 || redirection->type == 4)
		ptr_fd = &stream->descriptors.std_in;
	save_fd = *ptr_fd;
	if (redirection->type == 4)
		*ptr_fd = ft_note_start(config, name_file);
	else
		*ptr_fd = open(name_file->string, flags[redirection->type - 1], 0644);
	if (*ptr_fd == -1)
	{
		*ptr_fd = save_fd;
		return (ft_error_handler(config, stream, name_file, 1));
	}
	ft_parse_element_run(config, stream, redirection->element);
	close(*ptr_fd);
	ft_line_del(name_file);
	*ptr_fd = save_fd;
}
