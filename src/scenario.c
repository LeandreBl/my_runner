/*
** EPITECH PROJECT, 2017
** runner
** File description:
** scenario loop
*/

#include "runner.h"

static void	scroll_bar(window_t *window, sprite_t **sprites, size_t nb, double offset)
{
  sfVector2f	scale;
  sfVector2f	pos;
  sfVector2u	size;

  size = sfTexture_getSize(sprites[scroll]->texture);
  scale.x = 1;
  scale.y = window->height / ((double)size.y);
  if (nb > 9)
    scale.y /= (nb - 9); 
  pos.x = window->width - size.x - 10;
  pos.y = -offset * 42;
  put_sprite_resize(window, sprites[scroll], pos, scale);
  put_word("Select your music to play !",
	   xy_vectorf(850, 5), window, sfBlack);
}

static void	display(window_t *window, sfbutton_t **buttons,
			sprite_t **sprites, double offset)
{
  int		i;
  sfVector2f	pos;

  i = 0;
  display_sky(window, sprites[sky]);
  pos.x = 50;
  while (buttons[i] != NULL)
  {
    pos.y = 50 + (50.0 * offset) + (i * 70);
    sfbutton_draw_name(window, buttons[i], pos, sfWhite);
    ++i;
  }
  scroll_bar(window, sprites, tablen(buttons), offset);
}

static void	init_data(data_pkt_t *data, window_t *window,
			  sprite_t **sprites, sfbutton_t **buttons)
{
  data->window = window;
  data->buttons = buttons;
  data->sprites = sprites;
  data->offset = 0;
  data->back = false;
}

int		scenario(window_t *window)
{
  sprite_t	**sprites;
  sfbutton_t	**buttons;
  data_pkt_t	data;
  evtptr_t	tab[4];

  init_tab_scenario(tab);
  if (load_script("sprites/script.csfml", "scenario", &sprites) == -1 ||
      load_scenario_buttons(&buttons, sprites) == -1)
    return (-1);
  init_data(&data, window, sprites, buttons);
  while (sfRenderWindow_isOpen(window->window) && data.back != true)
  {
    window_clear(window);
    ptr_pollevent(window, tab, sizeof(tab) / sizeof(*tab), &data);
    display(window, buttons, sprites, data.offset);
    window_refresh(window);
  }
  free_sfbuttons(buttons);
  free_sprites(sprites);
  return (0);
}
