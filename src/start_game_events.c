/*
** EPITECH PROJECT, 2017
** runner
** File description:
** ingame events handlers
*/

#include "runner.h"

int		play_button(window_t *window, sfEvent *event, void *data)
{
  data_pkt_t	*pkt;
  sfVector2i	pos;

  (void) window;
  pkt = (data_pkt_t *)data;
  pos.x = event->mouseButton.x;
  pos.y = event->mouseButton.y;
  sfbutton_exec(*(pkt->buttons), pos, data);
  pkt->back = true;
  return (0);
}

int		leave_ingame(window_t *window, sfEvent *event, void *data)
{
  data_pkt_t	*ptr;

  (void) window;
  ptr = (data_pkt_t *)data;
  if (event != NULL && event->type == sfEvtKeyPressed && event->key.code != sfKeyEscape)
    return (0);
  //TODO pause / quit screen
  ptr->back = true;
  return (0);
}
