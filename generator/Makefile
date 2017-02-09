


CC		=	gcc

NAME		=	generateur

CFLAGS		+=	-I./include \
			-Wall -W -Wextra \
			-O3

RM		=	rm -f

SRC		=	src/main.c \
			src/algo.c \
			src/disp_labi.c \
			src/utils.c \
			src/imparfait.c

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
