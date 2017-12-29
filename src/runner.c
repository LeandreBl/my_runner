/*
** EPITECH PROJECT, 2017
** runner
** File description:
** running loop
*/

#include "runner.h"

static int	game(game_t *data)
{
  while (sfRenderWindow_isOpen(data->window->window)
	 && data->leave == false)
  {
    window_clear(data->window);
    if (KP(sfKeyEscape))
      data->leave = true;
    window_refresh(data->window);
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
  data_block.leave = false;
  return (game(&data_block));
}
