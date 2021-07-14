/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 21:20:07 by telron            #+#    #+#             */
/*   Updated: 2021/07/01 15:45:08 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "minishell_includes.h"
# include "minishell_global_variables.h"
# include "minishell_structs.h"
# include "minishell_parse.h"
# include "minishell_builtins.h"
# include "minishell_environment.h"
# include "key_setting.h"

# ifndef PATH_HISTORY
#  define PATH_HISTORY 0
# endif

void			shell(void);
void			ft_exit(t_shell *config);
void			ft_save_history(t_shell *config);
void			ft_load_history(t_shell *config);
int				ft_launch_executable(t_shell *config, t_executable *executable);
void			ft_reload_fd(t_descriptors *fd_saved);
void			ft_dup_fd(t_descriptors *fd_saved, t_executable *executable);
char			*ft_find_command(t_shell *config, const char *line_command);
void			ft_put_exit_code(char *destination, int exit_code);
void			ft_put_line(t_shell *config, t_line *line_command);
void			ft_input(t_shell *config);
void			ft_init_mode(t_shell *config, t_view *view);
void			ft_reset_mode(t_shell *config);
void			ft_inp_mode(t_shell *config);
void			ft_buffer_insert(t_shell *config, char char_buffer);
void			ft_buffer_normal(t_shell *config, char char_buffer);
int				ft_note_start(t_shell *config, t_line *stop_world);
void			ft_note_normal(t_shell *config, char char_buffer);
int				ft_note(t_shell *config, char char_buffer);
void			ft_normal(t_shell *config, char char_buffer);
void			ft_insert(t_shell *config, char char_buffer);
int				ft_choice(t_shell *config, char char_buffer);
int				ft_choice_make(t_shell *config, t_dlist *dlist);
void			ft_script(t_shell *config, const char *filename);
void			ft_inp_sugnature_render(t_shell *config);
void			ft_add_number(t_line *line, size_t num);
void			ft_add_colon(t_line *line);
char			*ft_get_str_hot_key(t_shell *config);
size_t			ft_get_len_hot_key(t_shell *config);
void			ft_add_pwd(t_shell *config, t_line *line);
int				ft_env_from_pp_chr(t_shell *config, char *env[]);
char			*ft_env_get(t_shell *config, char *key);
int				ft_env_check_key(t_dict *dict, char *key);
char			**ft_env_dict_to_string(t_shell *config);
int				ft_env_print_for_export(t_shell *config);
int				ft_env_clear(t_shell *config);
int				ft_env_del(t_shell *config, char *key);
int				ft_env_change_value(\
							t_shell *config, \
							char *new_value, \
							char *key);
void			ft_delete_strings(char **strings);
int				ft_isatty(int fd);
int				ft_stdfd_is_tty(void);
void			ft_up(t_view *view, int count);
void			ft_down(t_view *view, int count);
void			ft_right(t_view *view, int count);
void			ft_put_n(t_view *view, int count);

void			ft_inp_view_render(t_shell *config);
void			ft_get_begin(t_shell *config);
void			ft_print_index(t_shell *config, size_t index);
size_t			ft_min(size_t first, size_t second);
void			ft_inp_init_draw(t_shell *config);
void			ft_to_line(t_shell *config, int index);
void			ft_del_commands(t_shell *config);

void			ft_inp_view_clean(t_view *view);
t_command		*ft_inp_command_get(t_shell *config);
t_command		*ft_inp_command_new(t_view *view);
int				ft_command_length(t_command *command);
void			ft_inp_command_delone(t_command *command);
void			ft_inp_command_render(t_shell *config);
void			ft_inp_command_reload_count_lines(t_command *command);
void			ft_inp_command_reload_len_prefix(t_command *command);
size_t			ft_inp_command_com2com_copy(\
							t_command *destination, \
							t_command *source, \
							size_t count_line);
size_t			ft_inp_command_com2com_copy_up(\
							t_command *destination, \
							t_command *source, \
							size_t count_line);
t_cmd_line		*ft_inp_cmd_line_new(t_command *command);
t_cmd_line		*ft_inp_cmd_line_new_up(t_command *command);
t_cmd_line		*ft_inp_cmd_line_new_to_dlist(t_dlist **dlist);
t_cmd_line		*ft_inp_cmd_line_get(t_shell *config);
size_t			ft_inp_cmd_line_get_count_lines(\
							t_cmd_line *cmd_line, \
							size_t index);
void			ft_inp_cmd_line_delone(t_cmd_line *cmd_line);
t_output_line	*ft_inp_output_line_new(\
							t_line *line, \
							size_t index, \
							size_t start, \
							size_t stop);
void			ft_inp_output_line_delete(t_output_line *output_line);
void			ft_inp_cursor_sync(t_shell *config);
size_t			ft_inp_get_length_number(size_t number);
size_t			*ft_inp_get_mode_digit_ptr(t_shell *config);
size_t			ft_inp_get_mode_digit(t_shell *config, size_t min);
t_dlist			*ft_parse_wildcard(t_line *str);
int				ft_parse_wildcard_recursion(\
							t_dlist **res, \
							t_line *pat, \
							t_line *org_pat);
char			**ft_wildcard_set_pattern_array(\
							t_line *pattern, \
							t_line **pattern_tmp);
int				ft_wildcard_find_str(\
							char **parts_pattern, \
							char *name, \
							char *pattern);
int				ft_parse_wildcard_recursion_set_path_and_pattern(\
							t_line **path, \
							t_line **pattern);
size_t			ft_strlen_c(const char *str, const char sep);
int				ft_ret(\
							t_line *path, \
							t_line *pattern, \
							t_line *pattern_tmp, \
							char **pattern_array);
void			ft_init_variable(\
							t_line **path, \
							char ***pat_arr, \
							t_line **pat_tmp);
int				ft_add_or_recursion(\
							t_dlist **res, \
							t_line *path, \
							t_line *tmp, \
							t_line *org_pat);
int				ft_wildcard_step(t_line *pattern);
t_dlist			*ft_prompt(t_shell *config, t_line *line);
int				ft_prompt_command_add_to_dlst(t_dlist *tmp_lst, t_dlist **res);
t_dlist			*ft_find_command_in_path(char *path, t_line *line);
t_dlist			*ft_find_command_in_history(t_line *pattern, t_dlist *history);

#endif
