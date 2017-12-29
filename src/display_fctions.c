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

void		display_player(game_t *game)
{
  sfVector2u	size;
  sfVector2u	match;
  sfVector2f	scale;
  sfVector2f	pos;

  size = sfTexture_getSize(game->sprites[player]->texture);
  match = sfTexture_getSize(game->sprites[cube1]->texture);
  scale.x = (float)match.x / (float)size.x;
  scale.y = (float)match.y / (float)size.y;
  pos.x = 50;
  pos.y = match.y * (game->player.pos.y) - match.y * 2.2;
  put_sprite_resize(game->window, game->sprites[player],
		    pos, scale);
}

void		display_runner(game_t *game)
{
  int		i;
  int		j;
  sfVector2u	size;
  sfVector2f	real;

  i = 0;
  display_sky(game->window, game->sprites[sky]);
  size = sfTexture_getSize(game->sprites[cube1]->texture);
  while (game->map[i] != NULL)
  {
    j = 0;
    while (game->map[i][j] != 0)
    {
      real.x = j * size.x - game->player.pos.x * size.x;
      real.y = i * size.y - size.y * 1.2;
      if (game->map[i][j] != ' ')
	put_sprite(game->window, game->sprites[(int)game->map[i][j]], real);
      ++j;
    }
    ++i;
  }
  display_player(game);
}
