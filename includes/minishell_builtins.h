/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtins.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 18:33:11 by aberry            #+#    #+#             */
/*   Updated: 2021/06/07 06:42:34 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BUILTINS_H
# define MINISHELL_BUILTINS_H

# include "minishell_structs.h"

int			ft_builtin_cd(t_shell *config, const char *argv[]);
int			ft_builtin_pwd(t_shell *config, const char *argv[]);
int			ft_builtin_export(t_shell *config, const char *argv[]);
int			ft_builtin_echo(t_shell *config, const char *argv[]);
int			ft_builtin_unset(t_shell *config, const char *argv[]);
int			ft_builtin_exit(t_shell *config, const char *argv[]);
int			ft_builtin_env(t_shell *config, char *const argv[]);

#endif
