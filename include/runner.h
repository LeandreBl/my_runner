/*
** EPITECH PROJECT, 2017
** runner
** File description:
** header
*/

#ifndef RUNNER_H_
# define RUNNER_H_

# include <stdbool.h>

# include "csfml.h"

# include "my.h"
# include "defines.h"
# include "colors.h"

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
}		sheet_e;

typedef struct	data_pkt_s
{
  bool		back;
  double	offset;
  window_t	*window;
  sfbutton_t	**buttons;
  sprite_t	**sprites;
}		data_pkt_t;

/* --------------------------- @a functions --------------------------- */
void	display_sky(window_t *window, sprite_t *sprite);
char	**generate_from_soundbuffer(sfSoundBuffer *buffer);
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
int	runner(void *data, sfbutton_t *this);
#endif /* !RUNNER_H_ */
