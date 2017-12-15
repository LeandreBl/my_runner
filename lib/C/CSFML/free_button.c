/*
** EPITECH PROJECT, 2017
** csfml
** File description:
** destroy button
*/

#include "csfml.h"

void		free_sfbuttons(sfbutton_t **buttons)
{
  int		i;

  if (buttons != NULL)
  {
    i = 0;
    while (buttons[i] != NULL)
    {
      free_sfbutton(buttons[i]);
      ++i;
    }
    sfree(&buttons);
  }
}

void		free_sfbutton(sfbutton_t *button)
{
  if (button != NULL)
  {
    sfree(&button->name);
    sfree(&button);
  }
}
