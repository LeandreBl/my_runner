/*
** quit.c for csfml in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue Apr  4 22:01:01 2017 Léandre Blanchard
** Last update Sat Jun  3 17:00:14 2017 Léandre Blanchard
*/

#include "csfml.h"

/*
** this fonction need to be added in a display loop
** this fonction does not return, but close the window
** in window_t->window, is the user clic on the 'x' o the window
** or press Escape (echap in french)
*/
void		close_win(window_t *win)
{
  sfVector2i    pos;

  pos = pos_mouse(win);
  if (pos.x >= win->width - 40 && pos.y <= 0 &&
      sfMouse_isButtonPressed(sfMouseLeft)
      && pos.x <= win->width && pos.y >= -40)
    sfRenderWindow_close(win->window);
  if (KP(sfKeyEscape))
    sfRenderWindow_close(win->window);
}
