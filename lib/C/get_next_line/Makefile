##
## EPITECH PROJECT, 2017
## get next line
## File description:
## makefile
##

NAME	= ../libgnl.a

CC	= gcc

ARCH	= ar rc

SRCS	= get_next_line.c

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
