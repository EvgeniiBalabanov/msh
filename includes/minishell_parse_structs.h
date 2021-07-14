/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parse_structs.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:56:12 by telron            #+#    #+#             */
/*   Updated: 2021/06/21 02:45:45 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PARSE_STRUCTS_H
# define MINISHELL_PARSE_STRUCTS_H

# include "minishell_includes.h"

# define SEQUENCE_CODE		1
# define PIPE_CODE			2
# define AND_CODE			3
# define OR_CODE			4
# define GROUP_CODE			5
# define STRING_CODE		6
# define IMMUTABLE_CODE		7
# define VARIABLE_CODE		8
# define SEPARATOR_CODE		9
# define REDIRECTION_CODE	10
# define TILDA_CODE			11
# define COMMAND_CODE		12

typedef struct s_descriptors
{
	int					std_in;
	int					std_out;
	int					std_err;
}						t_descriptors;

typedef struct s_stream
{
	t_descriptors		descriptors;
	int					exit_code;
}						t_stream;

typedef union u_content			t_content;
typedef struct s_parse_element	t_parse_element;

typedef struct s_executable
{
	t_descriptors		descriptors;
	const char			**argums;
}						t_executable;

typedef struct s_parse_sequence
{
	t_dlist				*dlist_element;
}						t_parse_sequence;

typedef struct s_parse_pipe
{
	t_parse_element		*left;
	t_parse_element		*right;
}						t_parse_pipe;

typedef struct s_parse_and
{
	t_parse_element		*element;
}						t_parse_and;

typedef struct s_parse_or
{
	t_parse_element		*element;
}						t_parse_or;

typedef struct s_parse_group
{
	t_parse_element		*element;
}						t_parse_group;

typedef struct s_parse_string
{
	t_line				*line;
}						t_parse_string;

typedef struct s_parse_immutable
{
	t_line				*line;
}						t_parse_immutable;

typedef struct s_parse_mark_two
{
	t_parse_element		*element;
}						t_parse_mark_two;

typedef struct s_parse_variable
{
	t_line				*line;
}						t_parse_variable;

typedef struct s_parse_separator
{
	t_line				*line;
}						t_parse_separator;

typedef struct s_parse_redirection
{
	t_parse_element		*element;
	t_dlist				*name_file;
	int					type;
}						t_parse_redirection;

typedef struct s_parse_tilda
{
}						t_parse_tilda;

typedef struct s_parse_command
{
	t_dlist				*dlist_argums;
}						t_parse_command;

union					u_content
{
	t_parse_sequence	sequence;
	t_parse_pipe		pipe;
	t_parse_and			and;
	t_parse_or			or;
	t_parse_group		group;
	t_parse_string		string;
	t_parse_immutable	immutable;
	t_parse_variable	variable;
	t_parse_separator	separator;
	t_parse_redirection	redirection;
	t_parse_command		command;
	t_parse_tilda		tilda;
};

struct					s_parse_element
{
	char				type;
	void				*checker;
	void				*run;
	void				*destructor;
	union u_content		content;
};

#endif
