/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 23:24:53 by telron            #+#    #+#             */
/*   Updated: 2021/07/06 22:24:13 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_reset_mode(t_shell *config)
{
	tcsetattr(config->view.fd_dev_tty, \
		TCSANOW, &config->term_saved_attributes);
}

void	ft_inp_mode(t_shell *config)
{
	struct termios	tattr;

	ft_memcpy(&tattr, &config->term_saved_attributes, sizeof(tattr));
	tattr.c_lflag &= ~(ICANON | ECHO | ISIG);
	tattr.c_cc[VMIN] = 0;
	tattr.c_cc[VTIME] = 1;
	tcsetattr(config->view.fd_dev_tty, TCSAFLUSH, &tattr);
}

void	ft_sighnd(int __attribute__((unused)) signo)
{
}

void	ft_on_terminal_resize(int __attribute__((unused)) n)
{
	ioctl(1, TIOCGWINSZ, &(g_winsize));
}

void	ft_init_mode(t_shell *config, t_view *view)
{
	tcgetattr(config->view.fd_dev_tty, &config->term_saved_attributes);
	signal(SIGINT, ft_sighnd);
	signal(SIGTERM, ft_sighnd);
	signal(SIGTSTP, ft_sighnd);
	signal(SIGQUIT, ft_sighnd);
	signal(SIGWINCH, ft_on_terminal_resize);
	ioctl(view->fd_dev_tty, TIOCGWINSZ, &(g_winsize));
	ft_memcpy(&(view->saved_winsize), &g_winsize, sizeof(struct winsize));
	ft_inp_mode(config);
}
