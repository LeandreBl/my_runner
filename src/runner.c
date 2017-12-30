/*
** EPITECH PROJECT, 2017
** runner
** File description:
** running loop
*/

#include "runner.h"

static void	display(game_t *game)
{
  (void) game;
}

static int	game(game_t *game)
{
  evtptr_t	tab[4];

  init_tab_runner(tab);
  sfMusic_play(game->music);
  while (sfRenderWindow_isOpen(game->window->window)
	 && game->leave == false)
  {
    window_clear(game->window);
    ptr_pollevent(game->window, tab, sizeof(tab) / sizeof(*tab), game);
    runner_move(game);
    display_runner(game);
    display(game);
    window_refresh(game->window);
  }
  return (0);
}

int		runner(void *data, sfbutton_t *this)
{
  game_t	data_block;
  data_pkt_t	*ptr;

  (void) this;
  ptr = (data_pkt_t *)data;
  data_block.window = ptr->window;
  data_block.map = ptr->map;
  data_block.music = ptr->music;
  data_block.sprites = ptr->sprites;
  data_block.buttons = NULL;
  data_block.player.pos = xy_vectorf(0, tablen(ptr->map) - 1);
  data_block.player.type = 0;
  data_block.player.rotation = 0;
  data_block.player.speed = DEFAULT_SPEED;
  data_block.leave = false;
  return (game(&data_block));
}
