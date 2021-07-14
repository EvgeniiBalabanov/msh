.PHONY:	all clean fclean re

NAME		=	libft.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -I./includes -O3

NAME_FILES	=	ft_atoi.c ft_isalpha.c ft_itoa.c ft_memcpy.c ft_putendl_fd.c\
				ft_strchr.c ft_strlcpy.c ft_strnstr.c ft_tolower.c ft_bzero.c\
				ft_isascii.c ft_memccpy.c ft_memmove.c ft_putnbr_fd.c\
				ft_strdup.c ft_strlen.c ft_strrchr.c ft_toupper.c ft_calloc.c\
				ft_isdigit.c ft_memchr.c ft_memset.c ft_putstr_fd.c\
				ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_isalnum.c\
				ft_isprint.c ft_memcmp.c ft_putchar_fd.c ft_split.c\
				ft_strlcat.c ft_strncmp.c ft_substr.c ft_strcmp.c\
				ft_malloc_content.c ft_strcpy.c ft_strcmp_i.c

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