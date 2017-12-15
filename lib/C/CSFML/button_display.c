/*
** EPITECH PROJECT, 2017
** csfml
** File description:
** button display functions
*/

#include "csfml.h"

void		sfbutton_draw(window_t *window, sfbutton_t *button, sfVector2f pos)
{
  pos_mouse(window);
  button->pos = pos;
  if (sfbutton_ispressed(button, window->mouse))
  {
    sfSprite_setColor(button->sprite->sprite, sfColor_fromRGB(100, 100, 100));
    put_sprite(window, button->sprite, button->pos);
    sfSprite_setColor(button->sprite->sprite, sfWhite);
  }
  else
    put_sprite(window, button->sprite, button->pos);
}

void		sfbutton_draw_name(window_t *window, sfbutton_t *button,
				   sfVector2f rpos, sfColor color)
{
  sfVector2f	pos;
  sfVector2f    size;

  button->pos = rpos;
  size.x = my_strlen(button->name) * 12;
  size.y = (nb_of(button->name, '\n') + 1) * 24;
  pos.x = button->pos.x + (button->size.x - size.x) / 2;
  pos.y = button->pos.y + (button->size.y - size.y) / 2;
  sfbutton_draw(window, button, rpos);
  put_word(button->name, pos, window, color);
}

void		sfbutton_draw_name_all(window_t *window, sfbutton_t **buttons,
				       sfColor color)
{
  int		i;

  i = 0;
  while (buttons != NULL && buttons[i] != NULL)
  {
    sfbutton_draw_name(window, buttons[i], buttons[i]->pos, color);
    ++i;
  }
}

void		sfbutton_draw_all(window_t *window, sfbutton_t **buttons)
{
  int		i;

  i = 0;
  while (buttons != NULL && buttons[i] != NULL)
  {
    sfbutton_draw(window, buttons[i], buttons[i]->pos);
    ++i;
  }
}
