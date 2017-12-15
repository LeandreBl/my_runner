/*
** clear_win.c for clear_win in /home/leandre/Rushs/scroller/lib/CSFML
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Mar 31 14:04:57 2017 Léandre Blanchard
** Last update Mon Nov 13 22:27:06 2017 Léandre Blanchard
*/

#include "csfml.h"
/*
** clear the window_t current's sprites
*/
void            window_clear(window_t *window)
{
  sfRenderWindow_clear(window->window, sfWhite);
}

/* Updates the window from the pixels */
void            window_update(window_t *window)
{
  sfTexture_updateFromPixels(window->frame->texture, window->pixels,
			     window->width, window->height, 0, 0);
  put_sprite(window, window->frame, ORIGIN);
}

/*
** refresh the window by displaying the sprites,
** and the pixels contained in window->pixels
*/
void            window_refresh(window_t *window)
{
  window_update(window);
  sfRenderWindow_display(window->window);
}

/*
** Fill all the pixel of window->pixels with color
*/
void		clear_color(window_t *window, sfColor color)
{
  int		x;
  int		y;

  y = 0;
  while (y < window->height)
  {
    x = 0;
    while (x < window->width)
    {
      my_put_pixel(window, x, y, color);
      ++x;
    }
    y++;
  }
}

/*
** fill all the bytes of the pixel array in window_t
** with blank
*/
void		clear_white(window_t *window)
{
  int		i;
  int		*pixels;

  pixels = (int *)window->pixels;
  i = 0;
  while (i != window->height * window->width)
    pixels[i++] = 255;
}
