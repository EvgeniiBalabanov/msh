/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_executable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:19:14 by aberry            #+#    #+#             */
/*   Updated: 2021/06/25 09:45:31 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_builtin(t_shell *config, t_executable *executable)
{
	size_t			counter;
	t_descriptors	fd_saved;
	int				exit_code;
	static void		*builtins[][2] = {{"export", ft_builtin_export}, \
	{"cd", ft_builtin_cd}, {"echo", ft_builtin_echo}, {"env", ft_builtin_env}, \
	{"pwd", ft_builtin_pwd}, {"unset", ft_builtin_unset}, \
	{"exit", ft_builtin_exit}, {0, 0}};

	counter = 0;
	while (*builtins[counter] && \
		ft_strcmp_i((char *)builtins[counter][0], executable->argums[0]))
		counter++;
	if (!*builtins[counter])
		return (-1);
	ft_dup_fd(&fd_saved, executable);
	if (config->view.mode != MODE_SCRIPT)
		ft_reset_mode(config);
	exit_code = ((int (*)(t_shell *, const char *[])) \
					builtins[counter][1])(config, executable->argums);
	if (config->view.mode != MODE_SCRIPT)
		ft_inp_mode(config);
	ft_reload_fd(&fd_saved);
	return (exit_code);
}

static void	ft_print_message_exe(\
						t_shell *config, \
						int status, \
						t_executable *executable)
{
	char			string_exit_code[128];

	if (WIFSIGNALED(status) && WTERMSIG(status) && !config->is_child)
	{
		ft_put_exit_code(string_exit_code, status);
		ft_error_print(config, "ft_launch_executable", executable->argums[0], \
															string_exit_code);
	}
}

static void	ft_launch_execve(\
					t_shell *config, \
					t_executable *executable, \
					int *status, \
					char *path_bin)
{
	pid_t			cpid;
	t_descriptors	fd_saved;

	ft_dup_fd(&fd_saved, executable);
	if (config->view.mode != MODE_SCRIPT)
		ft_reset_mode(config);
	cpid = fork();
	if (!cpid)
	{
		if (config->view.mode != MODE_SCRIPT)
			ft_reset_mode(config);
		execve(path_bin, (char *const *)executable->argums, \
											ft_env_create_env(config));
		exit(-1);
	}
	waitpid(cpid, status, 0);
	ft_print_message_exe(config, *status, executable);
	if (config->view.mode != MODE_SCRIPT)
		ft_inp_mode(config);
	ft_reload_fd(&fd_saved);
}

int	ft_launch_executable(t_shell *config, t_executable *executable)
{
	int				status;
	char			*path_bin;

	if (!executable->argums[0])
		return (0);
	status = ft_is_builtin(config, executable);
	if (status != -1)
		return (status);
	path_bin = ft_find_command(config, executable->argums[0]);
	if (!path_bin)
	{
		ft_error_print(config, "ft_launch_executable", \
							executable->argums[0], "command not found");
		return (127);
	}
	ft_launch_execve(config, executable, &status, path_bin);
	free(path_bin);
	return (status);
}
