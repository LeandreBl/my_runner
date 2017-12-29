##
## EPITECH PROJECT, 2017
## printf
## File description:
## makefile
##

NAME	= ../libdefault.a

CC	= gcc

ARCH	= ar rc

SRCS	= char_binary.c
SRCS	+= clipboard.c
SRCS	+= convert_endian.c
SRCS	+= dir_filenames.c
SRCS	+= display_inside.c
SRCS	+= end_with.c
SRCS	+= epur_str.c
SRCS	+= file_data.c
SRCS	+= file_size.c
SRCS	+= free_tab.c
SRCS	+= full_read.c
SRCS	+= get_ip.c
SRCS	+= insert.c
SRCS	+= load_file.c
SRCS	+= max_len.c
SRCS	+= my_alloc_tab.c
SRCS	+= my_calloc.c
SRCS	+= my_get_float.c
SRCS	+= my_getnbr.c
SRCS	+= my_intlen.c
SRCS	+= my_memcpy.c
SRCS	+= my_putchar.c
SRCS	+= my_put_nbr.c
SRCS	+= my_putstr.c
SRCS	+= put_tab.c
SRCS	+= revstr.c
SRCS	+= my_strcat.c
SRCS	+= my_strcmp.c
SRCS	+= my_strcpy.c
SRCS	+= my_strdup.c
SRCS	+= my_strlen.c
SRCS	+= my_strstr.c
SRCS	+= my_str_to_wordtab.c
SRCS	+= my_total_len.c
SRCS	+= nb_of.c
SRCS	+= put_tab.c
SRCS	+= realloc.c
SRCS	+= remove_str.c
SRCS	+= replace.c
SRCS	+= revstr.c
SRCS	+= revtab.c
SRCS	+= rm_ascii.c
SRCS	+= save_as.c
SRCS	+= save_file.c
SRCS	+= sfree.c
SRCS	+= shift.c
SRCS	+= sort_tab.c
SRCS	+= tab_append.c
SRCS	+= tabdup.c
SRCS	+= tablen.c
SRCS	+= total_name.c
SRCS	+= zeros.c
SRCS	+= isacmd.c
SRCS	+= memset.c
SRCS	+= swap.c
SRCS	+= socket.c

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
