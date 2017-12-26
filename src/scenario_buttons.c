/*
** EPITECH PROJECT, 2017
** runner
** File description:
** scenario buttons
*/

#include "runner.h"

int		scenario_scroll(window_t *window, sfEvent *event, void *data)
{
  double        value;
  data_pkt_t	*ptr;

  ptr = (data_pkt_t *)data;
  value = (double)event->mouseWheelScroll.delta / 4;
  if (ptr->offset + value <= 0
      && (50 + (50.0 * (ptr->offset + value) + (tablen(ptr->buttons) - 1)
		* 70)) >= window->height - 120)
    ptr->offset += value;
  return (0);
}

int		leave_scenario(window_t *window, sfEvent *event, void *data)
{
  data_pkt_t	*ptr;
  //TODO exit screen

  (void) window;
  ptr = (data_pkt_t *)data;
  if (event != NULL && event->type == sfEvtKeyPressed
      && event->key.code != sfKeyEscape)
    return (0);
  ptr->back = true;
  return (0);
}

int		scenario_buttons(window_t *window, sfEvent *event, void *data)
{
  data_pkt_t	*ptr;

  ptr = (data_pkt_t *)data;
  button_poll_event(window, event, ptr->buttons, data);
  return (0);
}
