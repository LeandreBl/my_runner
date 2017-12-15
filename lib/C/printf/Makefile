##
## EPITECH PROJECT, 2017
## printf
## File description:
## makefile
##

NAME	= ../libprintf.a

CC	= gcc

ARCH	= ar rc

SRCS	= fd_put.c
SRCS	+= fd_put_unsigned.c
SRCS	+= format_gesture.c
SRCS	+= printf.c
SRCS	+= va_cutstr.c
SRCS	+= va_fd_len.c
SRCS	+= va_printf.c
SRCS	+= va_put_base.c
SRCS	+= va_put.c
SRCS	+= va_put_tab.c
SRCS	+= va_put_unsigned.c

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
