##
## Makefile for t in /home/gaby/rendu/Dantestar/largeur/
##
## Made by Gabriel de Blois
## Login   <de-blo_g@epitech.eu>
##
## Started on  Wed May 11 14:45:11 2016 Gabriel de Blois
## Last update Wed May 11 17:47:42 2016 Gabriel de Blois
##

CC		=	gcc

NAME		=	solver

CFLAGS		+=	-I./include \
			-Wall -W -Wextra \
			-O3

RM		=	rm -f

SRC		=	src/main.c \
			src/get_map.c \
			src/algo.c

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
