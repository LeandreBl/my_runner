/*
** EPITECH PROJECT, 2017
** runner
** File description:
** ingame well
*/

#include "runner.h"

static void	fill_data(data_pkt_t *data, window_t *window, sprite_t **sprites,
			  sfbutton_t **buttons)
{
  data->window = window;
  data->sprites = sprites;
  data->buttons = buttons;
  data->offset = 0;
  data->back = false;
}

static void	ingame(window_t *window, sprite_t **sprites,
		       sfMusic *music, const sfSoundBuffer *buffer)
{
  data_pkt_t	data;
  evtptr_t	tab[2];

  init_tab_ingame(tab);
  fill_data(&data, window, sprites, NULL);
  (void) buffer;
  sfMusic_play(music);
  while (sfRenderWindow_isOpen(window->window) &&
	 data.back == false)
  {
    window_clear(window);
    ptr_pollevent(window, tab, sizeof(tab) / sizeof(*tab), &data);
    window_refresh(window);
  }
  sfMusic_stop(music);
}

void		start_game(void *data, const char *filename)
{
  data_pkt_t	*ptr;
  sfMusic	*music;
  sfSoundBuffer	*buffer;

  music = sfMusic_createFromFile(filename);
  buffer = sfSoundBuffer_createFromFile(filename);
  if (music == NULL || buffer == NULL)
  {
    mdprintf(2, "[%sError%s] Could not open %s%s%s\n",
	     RED, RESET, YELLOW, filename, RESET);
    return;
  }
  ptr = (data_pkt_t *)data;
  ingame(ptr->window, ptr->sprites, music, buffer);
  sfMusic_destroy(music);
  sfSoundBuffer_destroy(buffer);
}
