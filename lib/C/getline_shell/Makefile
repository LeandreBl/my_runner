##
## EPITECH PROJECT, 2017
## getline_shell
## File description:
## makefile
##

NAME	= ../libgetlineshell.a

CC	= gcc

ARCH	= ar rc

SRCS	= getline_shell.c
SRCS	+= getline_shell_builtin.c
SRCS	+= getline_shell_cursor.c
SRCS	+= getline_shell_hist.c
SRCS	+= getline_shell_key.c
SRCS	+= getline_shell_prompt.c
SRCS	+= getline_shell_move.c

OBJS	= $(SRCS:.c=.o)

RM	= rm -f

CFLAGS	= -W -Werror -fPIC -g3 -Wall -Wextra -I ..

all: $(NAME)

$(NAME): $(OBJS)
	$(ARCH) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
