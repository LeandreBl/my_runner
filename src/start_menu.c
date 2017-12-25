/*
** EPITECH PROJECT, 2017
** runner
** File description:
** start menu
*/

#include "runner.h"

static void	display_sky(window_t *window, sprite_t **sprites)
{
  sfVector2u	size;
  sfVector2f	scale;

  size = sfTexture_getSize(sprites[1]->texture);
  scale.x = (double)window->width / size.x;
  scale.y = (double)window->height / size.y;
  put_sprite_resize(window, sprites[1], ORIGIN, scale);
}

static void	display_logo(window_t *window, sprite_t **sprites)
{
  sfVector2u	size;
  sfVector2f	pos;

  size = sfTexture_getSize(sprites[0]->texture);
  pos.x = (window->width - size.x) / 2;
  pos.y = window->height / 5;
  put_sprite(window, sprites[0], pos);
}

static int	load_buttons(sfbutton_t ***buttons, sprite_t **sprites)
{
  *buttons = my_calloc(sizeof(sfbutton_t **) * 4);
  if (*buttons == NULL)
    return (-1);
  (*buttons)[0] = sfbutton_create("Scenario", sprites[2],
				  ORIGIN, button_scenario);
  (*buttons)[1] = sfbutton_create("Endless", sprites[2],
				  ORIGIN, button_endless);
  (*buttons)[2] = sfbutton_create("Quit", sprites[2],
				  ORIGIN, button_quit_menu);
  return (0);
}

static void	display_buttons(window_t *window, sfbutton_t **buttons)
{
  sfVector2f	pos;
  sfVector2u	size;

  size = sfTexture_getSize(buttons[0]->sprite->texture);
  pos.y = window->height / 2;
  pos.x = (double)window->width/ 3 - size.x / 2.0;
  sfbutton_draw_name(window, buttons[0], pos, sfWhite);
  pos.x = (double)window->width * 2.0 / 3.0 - size.x / 2.0;
  sfbutton_draw_name(window, buttons[1], pos, sfWhite);
  pos.y = window->height - size.y - 3;
  pos.x = 5;
  sfbutton_draw_name(window, buttons[2], pos, sfWhite);
}

int		start_menu(window_t *window)
{
  evtptr_t	tab[3];
  sprite_t	**sprites;
  sfbutton_t	**buttons;
  data_pkt_t	data;

  init_tab_menu(tab);
  if (load_script("sprites/script.csfml", "start menu", &sprites) == -1 ||
      load_buttons(&buttons, sprites) == -1)
    return (-1);
  data.window = window;
  data.sprites = sprites;
  data.buttons = buttons;
  while (sfRenderWindow_isOpen(window->window))
  {
    window_clear(window);
    ptr_pollevent(window, tab, sizeof(tab) / sizeof(*tab), &data);
    display_sky(window, sprites);
    display_logo(window, sprites);
    display_buttons(window, buttons);
    window_refresh(window);
  }
  free_sfbuttons(buttons);
  free_sprites(sprites);
  return (0);
}
