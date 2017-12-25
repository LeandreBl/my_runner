##
## EPITECH PROJECT, 2017
## malloc
## File description:
## makefile
##

NAME	= ../libmy_malloc.a

CC	= gcc

ARCH	= ar rc

SRCS	= malloc.c
SRCS	+= free.c

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
