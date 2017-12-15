/*
** EPITECH PROJECT, 2017
** runner
** File description:
** main
*/

#include "runner.h"

int	main(void)
{
  sprite_t **sprites;

  if (load_script("sprites/script.csfml", "scene", &sprites) == -1)
    return (-1);
  free_sprites(sprites);
  return (0);
}
