/*
** EPITECH PROJECT, 2018
** runner
** File description:
** jump file fctions
*/

#include "runner.h"

char		get_block(game_t *game, sfVector2f xpos)
{
  sfVector2i	pos;
  
  pos = xy_vectori((int)xpos.x + 0.5, (int)xpos.y + 0.5);
  if (pos.x < (int)my_strlen(game->map[0]) && pos.x > 0 &&
      pos.y < (int)tablen(game->map) && pos.y > 0)
    return (game->map[pos.y][pos.x]);
  return (-1);
}

bool		can_jump(game_t *game)
{
  if (get_block(game, game->player.pos) != ' ')
    return (true);
  return (false);
}

bool		can_fall(game_t *game)
{
  sfVector2f	try;

  try = game->player.pos;
  (void) try;
  return (false);
}
