/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parse.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 18:56:28 by aberry            #+#    #+#             */
/*   Updated: 2021/06/21 03:48:20 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PARSE_H
# define MINISHELL_PARSE_H

# include "minishell_includes.h"
# include "minishell_parse_structs.h"

int					ft_run_cmd_lines(t_shell *config, size_t count_lines, \
						char from_the_first_line);
void				ft_run(t_shell *config, t_parse_element *element);

void				ft_error_print(t_shell *config, const char *func_name, \
						const char *message, const char *info);

t_parse_element		*ft_parse_build(t_shell *config, t_line *line);
t_dlist				*ft_parse_build_tokenize(t_shell *config, t_line *line);
t_parse_element		*ft_parse_build_variable(\
						t_shell *config, char **str, t_dlist **dlist);
t_parse_element		*ft_parse_build_quotes(t_shell *config, char **str, \
						t_dlist **dlist);
t_parse_element		*ft_parse_build_double_quotes(\
						t_shell *config, char **str, t_dlist **dlist);
t_parse_element		*ft_parse_build_string(t_shell *config, t_line **line, \
						t_dlist **dlist);
t_parse_element		*ft_build_separator(t_shell *config, char **str, \
						t_dlist **dlist, size_t count);
t_parse_element		*ft_parse_build_guard(t_shell *config, char **str, \
						t_dlist **dlist);
t_parse_element		*ft_parse_build_group(t_dlist *tokens);
t_parse_element		*ft_parse_build_sequence(t_shell *config, t_dlist *tokens);
t_parse_element		*ft_parse_build_pipe(t_shell *config, t_dlist *tokens);
t_parse_element		*ft_parse_build_command(t_dlist *tokens);
t_parse_element		*ft_parse_build_redirection(t_shell *config, \
															t_dlist *tokens);
t_parse_element		*ft_parse_build_tilda(t_shell *config, t_dlist *tokens);

/*
** 									ELEMENT CLASS
*/
void				ft_parse_element_checker(t_parse_element *element);
void				ft_parse_element_destructor(t_parse_element *element);
t_parse_element		*ft_parse_element_create(char *name, void *content);
void				ft_parse_element_run(\
								t_shell *config, \
								t_stream *stream, \
								t_parse_element *element);
void				ft_parse_element_to_immutable(t_parse_element *element);

/*
** 										AND CLASS
*/
void				ft_parse_and_checker(t_parse_and *and);
void				ft_parse_and_destructor(t_parse_and *element);
t_parse_element		*ft_parse_and_create(t_parse_element *element);
void				ft_parse_and_run(\
								t_shell *config, \
								t_stream *stream, \
								t_parse_and *element);

/*
** 										COMMAND CLASS
*/
void				ft_parse_command_checker(t_parse_command *command);
void				ft_parse_command_destructor(t_parse_command *command);
t_parse_element		*ft_parse_command_create(t_dlist *dlist_argums);
void				ft_parse_command_run(\
								t_shell *config, \
								t_stream *stream, \
								t_parse_command *element);

/*
** 										GROUP CLASS
*/
void				ft_parse_group_checker(t_parse_group *group);
t_parse_element		*ft_parse_group_create(t_parse_element *element);
void				ft_parse_group_destructor(t_parse_group *group);
void				ft_parse_group_run(\
								t_shell *config, \
								t_stream *stream, \
								t_parse_group *element);

/*
** 									MARK ONE CLASS
*/
void				ft_parse_immutable_checker(t_parse_immutable *immutable);
t_parse_element		*ft_parse_immutable_create(t_line *line);
void				ft_parse_immutable_destructor(t_parse_immutable *immutable);
void				ft_parse_immutable_run(\
								t_shell *config, \
								t_stream *stream, \
								t_parse_immutable *element);

/*
** 									OR CLASS
*/
void				ft_parse_or_checker(t_parse_or *or);
t_parse_element		*ft_parse_or_create(t_parse_element *element);
void				ft_parse_or_destructor(t_parse_or *or);
void				ft_parse_or_run(\
								t_shell *config, \
								t_stream *stream, \
								t_parse_or *element);

/*
** 									PIPE CLASS
*/
void				ft_parse_pipe_checker(t_parse_pipe *pipe);
t_parse_element		*ft_parse_pipe_create(\
								t_parse_element *left, \
								t_parse_element *right);
void				ft_parse_pipe_destructor(t_parse_pipe *pipe);
void				ft_parse_pipe_run(\
								t_shell *config, \
								t_stream *stream, \
								t_parse_pipe *element);

/*
** 									REDIRECTION CLASS
*/
void				ft_parse_redirection_checker(\
								t_parse_redirection *redirection);
t_parse_element		*ft_parse_redirection_create(\
								t_parse_element *element, \
								t_dlist *name_file, \
								int type);
void				ft_parse_redirection_destructor(\
								t_parse_redirection *redirection);
void				ft_parse_redirection_run(\
								t_shell *config, \
								t_stream *stream, \
								t_parse_redirection *element);

/*
** 									SEPARATOR CLASS
*/
void				ft_parse_separator_checker(t_parse_separator *separator);
t_parse_element		*ft_parse_separator_create(t_line *line);
void				ft_parse_separator_destructor(t_parse_separator *separator);
void				ft_parse_separator_run(\
								t_shell *config, \
								t_stream *stream, \
								t_parse_separator *element);
int					ft_parse_separator_is(\
								t_parse_element *element, \
								const char *string);

/*
** 									SEQUENCE CLASS
*/
void				ft_parse_sequence_checker(t_parse_sequence *sequence);
t_parse_element		*ft_parse_sequence_create(t_dlist *dlist_element);
void				ft_parse_sequence_destructor(t_parse_sequence *sequence);
void				ft_parse_sequence_run(\
								t_shell *config, \
								t_stream *stream, \
								t_parse_sequence *element);

/*
** 									STRING CLASS
*/
void				ft_parse_string_checker(t_parse_string *string);
t_parse_element		*ft_parse_string_create(t_line *line);
void				ft_parse_string_destructor(t_parse_string *string);
void				ft_parse_string_run(\
								t_shell *config, \
								t_stream *stream, \
								t_parse_string *element);

/*
** 									VARIABLE CLASS
*/
void				ft_parse_variable_checker(t_parse_variable *variable);
t_parse_element		*ft_parse_variable_create(t_line *line);
void				ft_parse_variable_destructor(t_parse_variable *variable);
void				ft_parse_variable_run(\
								t_shell *config, \
								t_stream *stream, \
								t_parse_variable *element);

/*
** 									TILDA CLASS
*/
void				ft_parse_tilda_checker(t_parse_tilda *tilda);
t_parse_element		*ft_parse_tilda_create(void);
void				ft_parse_tilda_destructor(t_parse_tilda *tilda);
void				ft_parse_tilda_run(\
								t_shell *config, \
								t_stream *stream, \
								t_parse_tilda *element);

#endif
