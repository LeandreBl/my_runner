/*
** EPITECH PROJECT, 2017
** runner
** File description:
** start menu
*/

#include "runner.h"

static int	leave(window_t *window, sfEvent *event, void *data)
{
  (void) event;
  (void) data;
  sfRenderWindow_close(window->window);
  return (0);
}

static void	init_tab(evtptr_t tab[])
{
  add_evt(&tab[0], sfEvtClosed, leave);
}

int		start_menu(window_t *window)
{
  evtptr_t	tab[1];
  sprite_t	**sprites;

  init_tab(tab);
  if (load_script("sprites/script.csfml", "start menu", &sprites))
    return (-1);
  while (sfRenderWindow_isOpen(window->window))
  {
    window_clear(window);
    ptr_pollevent(window, tab, sizeof(tab) / sizeof(*tab), NULL);
    put_sprite(window, sprites[0], ORIGIN);
    window_refresh(window);
  }
  free_sprites(sprites);
  return (0);
}
