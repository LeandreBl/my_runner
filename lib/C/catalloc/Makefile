##
## EPITECH PROJECT, 2017
## printf
## File description:
## makefile
##

NAME	= ../libcatalloc.a

CC	= gcc

ARCH	= ar rc

SRCS	= catalloc.c
SRCS	+= catalloc_gesture.c
SRCS	+= catalloc_handlers.c
SRCS	+= va_catalloc.c
SRCS	+= va_catalloc_nb.c
SRCS	+= getlens.c
SRCS	+= total_alloc.c

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
