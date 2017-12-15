/*
** EPITECH PROJECT, 2017
** csfml
** File description:
** find struct with name
*/

#include "csfml.h"

sfbutton_t     	*button_by_name(sfbutton_t **buttons, const char *name)
{
  int		i;

  i = 0;
  while (buttons != NULL && buttons[i] != NULL)
  {
    if (my_strcmp(buttons[i]->name, name) == 0)
      return (buttons[i]);
    ++i;
  }
  return (NULL);
}

sprite_t	*sprite_by_name(sprite_t **sprites, const char *name)
{
  int		i;

  i = 0;
  while (sprites != NULL && sprites[i] != NULL)
  {
    if (my_strcmp(sprites[i]->name, name) == 0)
      return (sprites[i]);
    ++i;
  }
  return (NULL);
}
