/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_exit_code.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 23:19:05 by telron            #+#    #+#             */
/*   Updated: 2021/06/07 10:50:55 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_put_exit_code(char *destination, int exit_code)
{
	static char	*exit_codes[64] = {"Hangup", "Interrupt", "Quit", \
		"Illegal instruction", "Trace/breakpoint trap", "Aborted", "Bus error", \
		"Floating point exception", "Killed", "User defined signal 1", \
		"Segmentation fault", "User defined signal 2", "Broken pipe", \
		"Alarm clock", "Terminated", "Stack fault", "Child exited", \
		"Continued", "Stopped (signal)", "Stopped", "Stopped (tty input)", \
		"Stopped (tty output)", "Urgent I/O condition", \
		"CPU time limit exceeded", "File size limit exceeded", \
		"Virtual timer expired", "Profiling timer expired", "Window changed", \
		"I/O possible", "Power failure", "Bad system call", \
		"Real-time sig reserved by the C library for NPTL", \
		"Real-time sig reserved by the C library for NPTL", "Real-time sig 0", \
		"Real-time sig 1", "Real-time sig 2", "Real-time sig 3", \
		"Real-time sig 4", "Real-time sig 5", "Real-time sig 6", \
		"Real-time sig 7", "Real-time sig 8", "Real-time sig 9", \
		"Real-time sig 10", "Real-time sig 11", "Real-time sig 12", \
		"Real-time sig 13", "Real-time sig 14", "Real-time sig 15", \
		"Real-time sig 16", "Real-time sig 17", "Real-time sig 18", \
		"Real-time sig 19", "Real-time sig 20", "Real-time sig 21", \
		"Real-time sig 22", "Real-time sig 23", "Real-time sig 24", \
		"Real-time sig 25", "Real-time sig 26", "Real-time sig 27", \
		"Real-time sig 28", "Real-time sig 29", "Real-time sig 30"};

	if (1 <= exit_code && exit_code <= 64)
		ft_strcpy(destination, exit_codes[exit_code - 1]);
}
