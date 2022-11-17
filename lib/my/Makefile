##
## EPITECH PROJECT, 2020
## test
## File description:
## test
##

# Sources Related Stuff
SRC     =	my_show_word_array.c	\
			my_putchar.c	\
			my_putstr.c	\
			my_reader.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a


# Global Stuff
CFLAGS	+=	-W -Wall -Wextra

CFLAGS	+=	-Iinclude

CC	=	gcc

RM	=	rm -f


# Rules
%.o: %.c
	@$(CC) -c -o $@ $< $(CFLAGS) $(LDFLAGS)

all:	$(NAME)

$(NAME):	$(OBJ)	$(OBJ_MAIN)
	@ar rc $(NAME) $(OBJ)
	@printf "[\033[0;34mBuild\033[0m] % 35s\n" $(NAME) | tr ' ' '-'
	@cp libmy.a ../

clean:
	@$(RM) $(NAME)
	@$(RM) ../$(NAME)

fclean:	clean
	@$(RM) $(OBJ)

re: fclean all

.PHONY: re fclean clean all
