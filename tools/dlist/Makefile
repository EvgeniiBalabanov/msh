.PHONY:	all clean fclean re

NAME		=	libdlist.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -I ./includes

NAME_FILES	=	ft_dlstadd_left.c ft_dlstclear_right.c ft_dlstiter_right.c\
				ft_dlstright.c ft_dlstadd_right.c ft_dlstdelone.c\
				ft_dlstiteri.c ft_dlstsize.c\
				ft_dlstadd_right_content.c ft_dlstadd_left_content.c\
				ft_dlstiteri_right.c ft_dlstsize_left.c ft_dlstadd_sort.c\
				ft_dlstiter_all_left.c ft_dlstleft.c ft_dlstsize_right.c\
				ft_dlstclear.c ft_dlstiter_all_right.c ft_dlstmap.c\
				ft_dlstclear_left.c ft_dlstiter_left.c ft_dlstnew.c\
				ft_dlstcopy_right.c ft_dlstcopy_left.c ft_dlstinsert.c\
				ft_dlstrelation.c ft_dlstget.c ft_dlstget_content.c

FILES		=	$(addprefix ./src/, $(NAME_FILES))

OBJS		=	$(FILES:.c=.o)

all:		${NAME}

${NAME}:	$(OBJS)
	ar rcs ${NAME} ${OBJS}

clean:
	rm -rf ${OBJS}

fclean:		clean
	rm -rf ${NAME}

re:			fclean all