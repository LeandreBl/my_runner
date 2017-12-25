##
## EPITECH PROJECT, 2017
## lbl-libc
## File description:
## makefile
##

NAME	= libmy.a

CC	= gcc

MAKE	= make -C

USE_CSFML := y

SRCS	= libcatalloc.a
SRCS	+= libdefault.a
SRCS	+= libgetlineshell.a
SRCS	+= libgnl.a
SRCS	+= libmy_malloc.a
SRCS	+= libprintf.a
ifdef USE_CSFML
SRCS	+= libmy_csfml.a
endif

RM	= rm -f

all: $(NAME)

$(NAME):
	$(MAKE) catalloc
	$(MAKE) printf
	$(MAKE) default
	$(MAKE) getline_shell
	$(MAKE) get_next_line
	$(MAKE) malloc
ifdef USE_CSFML
	$(MAKE) CSFML
endif
	ar rcT $(NAME) $(SRCS)
clean:
	$(MAKE) catalloc clean
	$(MAKE) printf clean
	$(MAKE) default clean
	$(MAKE) getline_shell clean
	$(MAKE) get_next_line clean
	$(MAKE) malloc clean
ifdef USE_CSFML
	$(MAKE) CSFML clean
endif
	$(RM) $(SRCS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
