/*
** EPITECH PROJECT, 2017
** runner
** File description:
** ingame events handlers
*/

#include "runner.h"

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
