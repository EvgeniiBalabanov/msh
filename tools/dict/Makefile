.PHONY:			all clean fclean re

NAME		=	libdict.a

T_NAME		=	test.o

N_DIR		=	./src/

T_DIR		=	./test/

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -I ./includes -I ../libft/includes -I ../list/includes

NAME_FILES	=	ft_dict_add.c ft_dict_get.c ft_dict_init.c\
				ft_dict_get_elem_by_key.c ft_dict_rem.c ft_dict_clean.c\
				ft_dict_elem_init.c ft_dict_get_keys.c ft_dict_del.c\
				ft_dict_hash_function.c ft_dict_double.c

TEST_FILES	=	main.c

N_FILES		=	$(addprefix ${N_DIR}, $(NAME_FILES))

T_FILES		=	$(addprefix ${T_DIR}, $(TEST_FILES))

N_OBJS		=	$(N_FILES:.c=.o)

T_OBJS		=	$(T_FILES:.c=.o)

all:		${NAME}

${NAME}:	$(N_OBJS)
	ar rcs ${NAME} ${N_OBJS}

debug:		CFLAGS	+= -fsanitize=address -g
debug:		all;

test:		all $(T_OBJS)
	${CC} -o ${T_NAME} -fsanitize=address -g -L . -L ../libft/ -L ../list/ -llist -ldict -lft -I ${T_DIR} ${T_OBJS}

clean:
	rm -rf ${N_OBJS} ${T_OBJS}

fclean:	clean
	rm -rf ${NAME} ${T_NAME}

re:	fclean all