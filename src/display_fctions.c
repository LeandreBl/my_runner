/*
** EPITECH PROJECT, 2017
** runner
** File description:
** @a display
*/

#include "runner.h"

void		display_sky(window_t *window, sprite_t *sprite)
{
  sfVector2u    size;
  sfVector2f    scale;

  size = sfTexture_getSize(sprite->texture);
  scale.x = (double)window->width / size.x;
  scale.y = (double)window->height / size.y;
  put_sprite_resize(window, sprite, ORIGIN, scale);
}

void		display_runner(game_t *game)
{
  (void) game;
}
