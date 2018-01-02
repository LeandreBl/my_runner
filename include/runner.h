/*
** EPITECH PROJECT, 2017
** runner
** File description:
** header
*/

#ifndef RUNNER_H_
# define RUNNER_H_

# include <stdbool.h>
# include <stdint.h>

# include "csfml.h"

# include "my.h"
# include "defines.h"
# include "colors.h"

# define WW		(game->window->width)
# define WH		(game->window->height)
# define WW2		(WW / 2)
# define WH2		(WH / 2)

# define DEFAULT_SPEED	(0.06)

# define GRAVITY_SCALE	(1.0001)

typedef enum
{
  cloud1,
  cloud2,
  cloud3,
  cloud4,
  cloud5,
  left_angle,
  cube1,
  right_angle,
  cube2,
  tree,
  moutain,
  sky,
  button,
  button2,
  scroll,
  player
}		sheet_e;

typedef struct	data_pkt_s
{
  bool		back;
  double	offset;
  window_t	*window;
  sfbutton_t	**buttons;
  sprite_t	**sprites;
  sfMusic	*music;
  char		**map;
}		data_pkt_t;

typedef struct	player_s
{
  float		speed;
  sfVector2f	pos;
  uint8_t	type;
  float		rotation;
  float		gravity;
}		player_t;

typedef struct	game_s
{
  player_t	player;
  window_t	*window;
  char		**map;
  sfMusic	*music;
  sprite_t	**sprites;
  sfbutton_t	**buttons;
  bool		leave;
}		game_t;

/* --------------------------- @a functions --------------------------- */
void	display_sky(window_t *window, sprite_t *sprite);
char	**generate_from_soundbuffer(sfSoundBuffer *buffer);
char	get_block(game_t *game, sfVector2f pos);
/* ----------------------------- menu loop ---------------------------- */
int	leave_menu(window_t *window, sfEvent *event, void *data);
int	button_quit_menu(void *data, sfbutton_t *this);
int	button_scenario(void *data, sfbutton_t *this);
int	button_endless(void *data, sfbutton_t *this);
int	menu_buttons(window_t *window, sfEvent *event, void *data);
void	init_tab_menu(evtptr_t tab[]);
int	start_menu(window_t *window);
/* ----------------------------- scenario ----------------------------- */
int	load_scenario_buttons(sfbutton_t ***buttons, sprite_t **sprites);
int	scenario_scroll(window_t *window, sfEvent *event, void *data);
int	scenario_buttons(window_t *window, sfEvent *event, void *data);
int	menu_buttons(window_t *window, sfEvent *event, void *data);
int	leave_scenario(window_t *window, sfEvent *event, void *data);
void	init_tab_scenario(evtptr_t tab[]);
int	scenario(window_t *window);
/* ----------------------------- in game ------------------------------ */
int	play_button(window_t *window, sfEvent *event, void *data);
int	leave_ingame(window_t *window, sfEvent *event, void *data);
void	init_tab_ingame(evtptr_t tab[]);
void	start_game(void *data, const char *filename);
/* ----------------------------- runner ------------------------------- */
bool	can_jump(game_t *game);
bool	can_fall(game_t *game);
void	init_tab_runner(evtptr_t tab[]);
void	display_player(game_t *game);
void	display_runner(game_t *game);
int	runner_jump(window_t *window, sfEvent *event, void *data);
void	runner_move(game_t *game);
int	runner_button_handler(window_t *window, sfEvent *event, void *data);
int	leave_runner(window_t *window, sfEvent *event, void *data);
int	runner(void *data, sfbutton_t *this);
#endif /* !RUNNER_H_ */
