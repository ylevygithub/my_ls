##
## EPITECH PROJECT, 2019
## make
## File description:
## make
## 

SRC =	lib.c \
		my_ls.c \
		rights.c \
		main.c

OBJ =	$(SRC:.c=.o)

NAME	=	my_ls

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
