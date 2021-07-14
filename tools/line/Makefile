.PHONY:			all clean fclean re test

NAME		=	libline.a

T_NAME		=	test.o

N_DIR		=	./src/

T_DIR		=	./test/

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -I ./includes -I ../libft/includes/ -O3

NAME_FILES	=	ft_line_add_chr.c ft_line_mem_up.c ft_line_mem_up_to.c\
				ft_line_cpy_str.c ft_line_new.c ft_line_add_line.c\
				ft_line_add_str.c ft_line_cpy_line.c ft_line_del.c\
				ft_line_create_chr.c ft_line_create_str.c ft_line_cpy_chr.c\
				ft_line_create_line.c ft_line_insert_chr.c ft_line_del_chr.c\
				ft_line_mem_realloc.c ft_line_add_line.c ft_line_cut_index.c\
				ft_line_sub_line.c \
				ft_line_get_count_byte_allocate.c ft_line_add_sub_line.c

TEST_FILES	=	main.c new_test.c cpy_str_test.c cpy_chr_test.c\
				create_chr_test.c create_str_test.c create_line_test.c\
				cpy_line_test.c add_chr_test.c add_str_test.c add_line_test.c\
				sub_line_test.c

N_FILES		=	$(addprefix ${N_DIR}, $(NAME_FILES))

T_FILES		=	$(addprefix ${T_DIR}, $(TEST_FILES))

N_OBJS		=	$(N_FILES:.c=.o)

T_OBJS		=	$(T_FILES:.c=.o)

all:		${NAME}

${NAME}:	$(N_OBJS)
	ar rcs ${NAME} ${N_OBJS}

test:		all $(T_OBJS)
	${CC} -o ${T_NAME} -L . -L ../libft/ -lline -lft -I ${T_DIR} ${T_OBJS}

clean:
	rm -rf ${N_OBJS} ${T_OBJS}

fclean:		clean
	rm -rf ${NAME} ${T_NAME}

re:			fclean all
