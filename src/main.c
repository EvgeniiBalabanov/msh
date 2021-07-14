/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:33:37 by telron            #+#    #+#             */
/*   Updated: 2021/06/29 12:24:44 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_init_view(t_shell *config)
{
	t_view	*view;

	view = &config->view;
	ft_init_mode(config, view);
	ft_load_history(config);
	ft_inp_keys_command_new(config);
	view->index_command += 1;
	view->mode = MODE_DEFAULT;
	view->fd_dev_tty = 1;
	if (!ft_stdfd_is_tty())
		view->fd_dev_tty = open("/dev/tty", O_RDWR);
	if (view->fd_dev_tty == -1)
	{
		ft_error_print(config, "ft_init_view", \
					"I can't connect to the terminal", \
					"open(\"/dev/tty\", ...)");
		ft_exit(config);
	}
}

int	main(int argc, const char *argv[], const char *env[])
{
	t_shell		config;
	const char	*filename;

	ft_bzero(&config, sizeof(t_shell));
	config.env_origin = env;
	ft_env_init(&config, env);
	if (argc > 1 || !ft_isatty(0))
	{
		config.view.mode = MODE_SCRIPT;
		filename = 0;
		if (argc > 1)
			filename = argv[1];
		ft_script(&config, filename);
	}
	else
	{
		ft_init_view(&config);
		ft_input(&config);
	}
	return (0);
}
