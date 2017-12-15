/*
** mouse_pos.c for mouse_pos in /home/leandre/Rushs/scroller/lib/CSFML
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Mar 31 14:00:42 2017 Léandre Blanchard
** Last update Sat Jun  3 17:02:21 2017 Léandre Blanchard
*/

#include "csfml.h"

/*
** Refresh the position of the mouse in window_t ptr,
** return the mouse position
** just return the position if window is NULL
*/
sfVector2i     	pos_mouse(window_t *window)
{
  if (window != NULL)
    window->mouse = sfMouse_getPositionRenderWindow(window->window);
  return (window->mouse);
}
