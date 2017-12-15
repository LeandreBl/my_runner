/*
** EPITECH PROJECT, 2017
** csfml
** File description:
** auto poll event
*/

#include "csfml.h"

#include "defines.h"
#include "colors.h"

int		button_poll_event(window_t *window, sfEvent *event, sfbutton_t **buttons,
				  void *data)
{
  sfVector2i	coord;
  int		i;

  i = 0;
  (void) window;
  coord = xy_vectori(event->mouseButton.x, event->mouseButton.y);
  while (buttons != NULL && buttons[i] != NULL)
  {
    sfbutton_exec(buttons[i], coord, data);
    ++i;
  }
  return (0);
}

void		add_evt(evtptr_t *index, int type, evt_t fction)
{
  index->type = type;
  index->fction = fction;
}

int		ptr_pollevent(window_t *window, evtptr_t tab[], int size, void *data)
{
  sfEvent	event;
  int		i;

  while (sfRenderWindow_pollEvent(window->window, &event))
  {
    i = 0;
    while (i < size)
    {
      if (event.type == tab[i].type)
      {
	if (tab[i].fction == NULL)
	  mdprintf(2, "[%sWarning%s] pollEven function pointer n°%d is NULL\n",
		   GREEN, RESET, i);
	else
	  if (tab[i].fction(window, &event, data) == -1)
	    return (-1);
      }
      ++i;
    }
  }
  return (0);
}
