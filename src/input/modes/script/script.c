/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   script.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:26:37 by aberry            #+#    #+#             */
/*   Updated: 2021/06/25 06:16:22 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_script_run(t_shell *config, t_line *line)
{
	t_parse_element	*element;

	element = ft_parse_build(config, line);
	if (!element)
		return (-1);
	ft_run(config, element);
	ft_parse_element_destructor(element);
	return (0);
}

static int	ft_open_file(t_shell *config, const char *filename)
{
	int				fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_error_print(config, "ft_script", filename, \
												"No such file or directory");
		config->exit_code = 1;
		ft_exit(config);
	}
	return (fd);
}

static void	ft_error_handler(t_shell *config, t_line *line, int fd)
{
	ft_error_print(config, "ft_script", "malloc", "line");
	if (fd > 0)
		close(fd);
	ft_line_del(line);
	ft_exit(config);
}

void	ft_script(t_shell *config, const char *filename)
{
	int				fd;
	int				op_buff;
	char			buff[1024];
	t_line			*line;

	if (filename)
		fd = ft_open_file(config, filename);
	else
		fd = 0;
	line = ft_line_create_str("");
	if (!line)
		ft_error_handler(config, line, fd);
	while (1)
	{
		op_buff = read(fd, buff, 1023);
		if (op_buff <= 0)
			break ;
		buff[op_buff] = '\0';
		if (!ft_line_add_str(line, buff))
			ft_error_handler(config, line, fd);
	}
	ft_script_run(config, line);
	ft_line_del(line);
	close(fd);
	ft_exit(config);
}
