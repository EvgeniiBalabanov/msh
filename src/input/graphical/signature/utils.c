/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 23:30:17 by telron            #+#    #+#             */
/*   Updated: 2021/06/10 10:18:33 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_str_hot_key(t_shell *config)
{
	if (config->view.mode == MODE_CHOICE)
		return (config->view.mode_choice.input_buffer);
	else if (config->view.mode == MODE_NOTE)
		return (config->view.mode_note.input_buffer);
	return (config->view.mode_normal.input_buffer);
}

size_t	ft_get_len_hot_key(t_shell *config)
{
	if (config->view.mode == MODE_CHOICE)
		return (config->view.mode_choice.buffer_length);
	else if (config->view.mode == MODE_NOTE)
		return (config->view.mode_note.buffer_length);
	return (config->view.mode_normal.buffer_length);
}

void	ft_add_number(t_line *line, size_t num)
{
	char	*buff;

	buff = ft_itoa(num);
	if (COLOR_DIGIT)
		ft_line_add_str(line, COLOR_DIGIT);
	ft_line_add_str(line, buff);
	if (COLOR_DIGIT)
		ft_line_add_str(line, COLOR_NORMAL);
	free(buff);
}

void	ft_add_colon(t_line *line)
{
	if (COLOR_COLON)
		ft_line_add_str(line, COLOR_COLON);
	ft_line_add_chr(line, ':');
	if (COLOR_COLON)
		ft_line_add_str(line, COLOR_NORMAL);
}

void	ft_add_pwd(t_shell *config, t_line *line)
{
	char		*home;
	char		*pwd;
	size_t		counter;
	size_t		len_home;

	home = ft_env_var_get_by_system(config, "HOME");
	pwd = ft_env_var_get_by_system(config, "PWD");
	len_home = 0;
	if (home)
		len_home = ft_strlen(home);
	if (COLOR_PWD)
		ft_line_add_str(line, COLOR_PWD);
	counter = 0;
	if (pwd && home && len_home && !ft_strncmp(pwd, home, len_home))
	{
		counter = len_home;
		ft_line_add_chr(line, '~');
	}
	if (pwd)
		ft_line_add_str(line, pwd + counter);
	if (COLOR_PWD)
		ft_line_add_str(line, COLOR_NORMAL);
}
