.PHONY:		all re clean fclean tools

NAME		=	minishell

CC			=	gcc

CONFIG_DIR	=	${HOME}/.msh/

HISTORY_DIR	=	history/

PATH_HISTORY=	${CONFIG_DIR}${HISTORY_DIR}

LIBS		=	$(addprefix ./tools/, libft list dlist line dict list)

INC			=	$(addprefix -I, $(addsuffix /includes/, . $(LIBS)))

CFLAGS		=	-Wall -Wextra -Werror -O3 -MMD $(INC) -D PATH_HISTORY=\"${PATH_HISTORY}\"

FILES		=	$(addprefix src/,\
					main.c exit.c save_history.c load_history.c\
					$(addprefix builtins/,\
						cd.c echo.c pwd.c unset.c exit.c export.c env.c\
					)\
					$(addprefix environment/,\
						$(addprefix export/,\
							print.c\
						)\
						$(addprefix for_executable/,\
							create_env.c\
						)\
						$(addprefix initialization/,\
							init.c\
							$(addprefix dynamic_value_functions/,\
								pwd.c random.c exit_code.c\
							)\
							$(addprefix initialization_functions/,\
								exit_code.c home.c oldpwd.c others.c pid.c pwd.c random.c shlvl.c\
							)\
						)\
						$(addprefix utils/,\
							variable_delone.c variable_new.c variable_get_by_user.c\
							variable_get_by_system.c variable_change_by_user.c\
							oldpwd_reload.c delete_env.c\
						)\
					)\
					$(addprefix prompt/,\
						$(addprefix command_in_history/,\
							command_in_history.c\
						)\
						$(addprefix promt_in_input/,\
							prompt.c prompt_utils.c\
						)\
						$(addprefix wildcard/,\
							ft_parse_wildcard_recursion_set_path_and_pattern.c wildcard.c ft_wildcard_find_str.c\
							ft_parse_wildcard_recursion.c ft_wildcard_set_pattern_array.c wildcard_utils.c\
						)\
					)\
					$(addprefix input/,\
						mode.c\
						$(addprefix modes/,\
							input.c\
							$(addprefix choice/,\
								choice.c\
							)\
							$(addprefix buffer/,\
								normal.c insert.c\
							)\
							$(addprefix main/,\
								normal.c insert.c\
							)\
							$(addprefix note/,\
								note.c note_start.c note_normal.c\
							)\
							$(addprefix script/,\
								script.c\
							)\
						)\
						$(addprefix graphical/,\
							$(addprefix cmd_line/,\
								get.c new.c delone.c\
							)\
							$(addprefix command/,\
								get.c new.c reload_len_prefix.c render.c com2com_copy.c\
								delone.c length.c\
							)\
							$(addprefix output_line/,\
								new.c delete.c\
							)\
							$(addprefix signature/,\
								render.c utils.c\
							)\
							$(addprefix utils/,\
								del_commands.c get_begin.c input_init_draw.c min.c move.c print_index.c to_line.c\
							)\
							$(addprefix view/,\
								clean.c render.c\
							)\
						)\
						$(addprefix keys/,\
							any_key.c to_line_or_end.c control_d.c cursor_right.c key_enter.c line_home.c\
							classic_enter.c to_line_or_home.c cursor_down.c cursor_down_or_nl.c cursor_up.c key_enter_line.c\
							skip_word_left.c command_down.c command_up.c cursor_left.c key_delete.c\
							line_end.c skip_word_right.c mode_to_normal.c mode_to_insert.c\
							new_line_down.c new_line_up.c cursor_left_to_insert.c cursor_right_to_insert.c\
							cursor_up_to_insert.c cursor_down_to_insert.c cursor_down_or_nl_to_insert.c line_add_clipboard.c\
							clipboard_paste_down.c clipboard_clear.c line_to_clipboard.c line_delete.c\
							tab_prompt.c command_new.c to_command_or_home.c command_delete.c\
							clipboard_paste_up.c insert_enter.c view_clipbord.c view_main_command.c\
						)\
						$(addprefix utils/,\
							ft_cursor_sync.c get_length_number.c get_mode_digit.c\
						)\
					)\
					$(addprefix interpreter/,\
						$(addprefix launch/,\
							launch_executable.c find_command.c ft_put_exit_code.c utils.c\
						)\
						$(addprefix parse/,\
							run.c error.c\
							$(addprefix build_tree/,\
								command.c build.c redirection.c tokenize.c group.c\
								pipe.c sequence.c variable.c double_quotes.c quotes.c\
								separator.c string.c guard.c tilda.c\
							)\
							$(addprefix classes/,\
								$(addprefix element/,\
									checker.c destructor.c run.c to_immutable.c\
								)\
								$(addprefix sequence/,\
									checker.c create.c destructor.c run.c\
								)\
								$(addprefix pipe/,\
									checker.c create.c destructor.c run.c\
								)\
								$(addprefix and/,\
									checker.c create.c destructor.c run.c\
								)\
								$(addprefix or/,\
									checker.c create.c destructor.c run.c\
								)\
								$(addprefix group/,\
									checker.c create.c destructor.c run.c\
								)\
								$(addprefix string/,\
									checker.c create.c destructor.c run.c\
								)\
								$(addprefix immutable/,\
									checker.c create.c destructor.c run.c\
								)\
								$(addprefix variable/,\
									checker.c create.c destructor.c run.c\
								)\
								$(addprefix separator/,\
									checker.c create.c destructor.c run.c is_separator.c\
								)\
								$(addprefix redirection/,\
									checker.c create.c destructor.c run.c\
								)\
								$(addprefix tilda/,\
									checker.c create.c destructor.c run.c\
								)\
								$(addprefix command/,\
									checker.c create.c destructor.c run.c\
								)\
							)\
						)\
					)\
					$(addprefix utils/,\
						delete_strings.c ft_isatty.c ft_stdfd_is_tty.c\
					)\
				)

OBJS		=	$(FILES:.c=.o)
DEPENDS		=	$(OBJS:.o=.d)

all:		$(NAME)

debug:		CFLAGS	+= -fsanitize=address -g
debug:		all;

install:	all
			ln ./${NAME} /usr/local/bin/msh
			mkdir ${CONFIG_DIR}
			mkdir ${PATH_HISTORY}

uninstall:	fclean
			rm -rf /usr/local/bin/msh
			rm -rf ${CONFIG_DIR}
			rm -rf ${PATH_HISTORY}

$(NAME):	$(OBJS) | tools
	${CC} ${CFLAGS} ${OBJS} $(addprefix -L, $(LIBS)) -ldlist -lft -lline -ldict -llist -o ${NAME}

define		ft_tools
	for library in $(LIBS) ; do \
		make $(1) -C $$library ;\
	done
endef

tools:
	$(call ft_tools, )

clean:
	$(call ft_tools, clean)
	rm -rf ${OBJS} ${DEPENDS}
	rm -rf ./sh_tests/out

fclean:		clean
	rm -rf ${NAME}
	$(call ft_tools, fclean)

re:			fclean all

norm:
	norminette ${FILES} ./includes/* ./tools/*
-include ${DEPENDS}
