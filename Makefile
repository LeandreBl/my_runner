##
## EPITECH PROJECT, 2017
## 
## File description:
## makefile
##

NAME		= runner

CC		= gcc

MAKE		= make -C

LIB		= -L./lib/C -lmy
LIB		+= -lmy_csfml
#LIB		+= -lc_graph_prog
LIB		+= -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-network -lcsfml-audio
LIB		+= -lm

SRCS		= src/main.c
SRCS		+= src/start_menu.c
SRCS		+= src/function_pointers_tab.c
SRCS		+= src/scenario.c
SRCS		+= src/init_scenario_buttons.c
SRCS		+= src/start_menu_buttons.c
SRCS		+= src/scenario_buttons.c
SRCS		+= src/start_game_events.c
SRCS		+= src/start_game.c
SRCS		+= src/generate_map_from_sound.c
SRCS		+= src/display_fctions.c
SRCS		+= src/runner.c
SRCS		+= src/runner_events.c

OBJ		= $(SRCS:.c=.o)

RM		= rm -f

CFLAGS		= -W -Werror -Wall -Wextra
CFLAGS		+= -I ./include
CFLAGS		+= -g3 -O3

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) lib/C
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LIB)
	@       tput setaf 2; cat include/signature; tput sgr0

clean:
	$(MAKE) lib/C clean
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) lib/C fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
