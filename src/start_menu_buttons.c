/*
** EPITECH PROJECT, 2017
** runner
** File description:
** start menu buttons
*/

#include "runner.h"

int		leave_menu(window_t *window, sfEvent *event, void *data)
{
  (void) data;
  if (event != NULL && event->type == sfEvtKeyPressed
      && event->key.code != sfKeyEscape)
    return (0);
  sfRenderWindow_close(window->window);
  return (0);
}

int		button_quit_menu(void *data, sfbutton_t *this)
{
  data_pkt_t	*ptr;

  (void) this;
  ptr = (data_pkt_t *)data;
  return (leave_menu(ptr->window, NULL, NULL));
}

int		button_scenario(void *data, sfbutton_t *this)
{
  data_pkt_t	*ptr;

  (void) this;
  ptr = (data_pkt_t *)data;
  scenario(ptr->window);
  return (0);
}

int		button_endless(void *data, sfbutton_t *this)
{
  data_pkt_t	*ptr;

  ptr = (data_pkt_t *)data;
  mprintf("Endless\n");
  (void) this;
  (void) ptr;
  return (0);
}

int		menu_buttons(window_t *window, sfEvent *event, void *data)
{
  data_pkt_t	*ptr;

  ptr = (data_pkt_t *)data;
  button_poll_event(window, event, ptr->buttons, data);
  return (0);
}
