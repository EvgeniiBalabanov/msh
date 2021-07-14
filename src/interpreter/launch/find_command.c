/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:01:27 by aberry            #+#    #+#             */
/*   Updated: 2021/06/27 18:43:46 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_strjoin_command(char **str, const char *line_command)
{
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	line = ft_strjoin("/", line_command);
	while (str[i])
	{
		tmp = str[i];
		str[i] = ft_strjoin(str[i], line);
		free(tmp);
		i++;
	}
	free(line);
}

static int	ft_check_one_path(t_shell *config, const char *line_command)
{
	struct stat		filestat;
	int				result;

	result = stat(line_command, &filestat);
	if (!result && !(filestat.st_mode & S_IXUSR))
	{
		ft_error_print(config, "ft_find_command", \
											line_command, "Permission denied");
		result = 1;
	}
	return (result);
}

static char	*ft_check_all_path(\
						t_shell *config, \
						const char *line_command, \
						char **all_path)
{
	size_t		counter;

	counter = 0;
	ft_strjoin_command(all_path, line_command);
	while (all_path[counter])
	{
		if (!ft_check_one_path(config, all_path[counter++]))
			return (ft_strdup(all_path[counter - 1]));
	}
	return ((char *)0);
}

char	*ft_find_command(t_shell *config, const char *line_command)
{
	t_variable	*variable;
	char		**all_path;
	char		*path_to_build;

	if (!ft_strcmp(line_command, ".") || !ft_strcmp(line_command, "..") \
													|| line_command[0] == 0)
		return (0);
	if (ft_strchr("./~", *line_command) && \
		ft_check_one_path(config, line_command) != -1)
		return (ft_strdup(line_command));
	variable = ft_dict_get(config->environment, "PATH");
	path_to_build = (char *)0;
	all_path = (char **)0;
	if (variable && (variable->attributes & VAR_ATTR_TO_EXECUTBLE) && \
						!(variable->attributes & VAR_ATTR_INVISIBLE))
	{
		all_path = ft_split(variable->value, ':');
		if (!all_path)
			return (path_to_build);
		path_to_build = ft_check_all_path(config, line_command, all_path);
	}
	ft_delete_strings(all_path);
	return (path_to_build);
}
