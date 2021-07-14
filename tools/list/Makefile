.PHONY:	all clean fclean re

NAME		=	liblist.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -I./includes

NAME_FILES	=	ft_lstadd_back.c ft_lstclear.c ft_lstiter.c ft_lstmap.c\
				ft_lstsize.c ft_lstadd_front.c ft_lstdelone.c\
				ft_lstlast.c ft_lstnew.c ft_lstadd_sort.c ft_lstiteri.c\
				ft_lstadd_back_content.c ft_lstadd_front_content.c

FILES		=	$(addprefix ./src/, $(NAME_FILES))

OBJS		=	$(FILES:.c=.o)

all:		${NAME}

${NAME}:	$(OBJS)
	ar rcs ${NAME} ${OBJS}

clean:
	rm -rf ${OBJS}

fclean:	clean
	rm -rf ${NAME}

re:	fclean all