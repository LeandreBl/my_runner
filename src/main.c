/*
** EPITECH PROJECT, 2017
** runner
** File description:
** main
*/

#include "runner.h"

int	main(void)
{
  window_t *window;

  window = init_window(720, 16.0 / 9.0, "runner", sfClose);
  if (window == NULL)
    return (-1);
  start_menu(window);
  free_window(window);
  return (0);
}
