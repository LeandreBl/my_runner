/*
** EPITECH PROJECT, 2017
** runner
** File description:
** runner event handler
*/

#include "runner.h"

int		leave_runner(window_t *window, sfEvent *event, void *data)
{
  game_t	*ptr;

  (void) window;
  ptr = (game_t *)data;
  if (event != NULL && event->type == sfEvtKeyPressed && event->key.code != sfKeyEscape)
    return (0);
  ptr->leave = true;
  return (0);
}

int		runner_button_handler(window_t *window, sfEvent *event, void *data)
{
  game_t	*ptr;

  ptr = (game_t *)data;
  button_poll_event(window, event, ptr->buttons, data);
  return (0);
}
