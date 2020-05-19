##
## EPITECH PROJECT, 2019
## 
## File description:
## 
##

SRC		=		my_putstr.c \
				my_putchar.c \
				my_put_nbr.c \
				my_strlen.c \
				my_ls.c

OBJ		=		$(SRC:.c=.o)

NAME	=	info_file

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) -g

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
