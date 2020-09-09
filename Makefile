NAME = rpn
SRC = rpn.c tools.c
CFLAGS = -Wall -Wextra -Werror -I.
CC = gcc

$(NAME): $(SRC) rpn.h

clean:
	$(RM) $(NAME)

re: clean $(NAME)
