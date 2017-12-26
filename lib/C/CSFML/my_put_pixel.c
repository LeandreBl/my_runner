/*
** my_put_pixel.c for put_pixel in /home/leandre/Rushs/scroller/lib/CSFML
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Mar 31 13:56:13 2017 Léandre Blanchard
** Last update Tue Nov  7 22:22:42 2017 Léandre Blanchard
*/

#include "csfml.h"

/*
** Put a pixel in window->pixels array of sfUint8
** at coordinates (x, y) with RGBA color "color"
** return -1 on error
*/
int		my_put_pixel(window_t *window, int x, int y, sfColor color)
{
  int		offset;

  if (x < 0 || y < 0)
    return (-1);
  if (x >= window->width || y >= window->height)
    return (-1);
  offset = (window->width * y + x) * 4;
  window->pixels[offset + 0] = color.r;
  window->pixels[offset + 1] = color.g;
  window->pixels[offset + 2] = color.b;
  window->pixels[offset + 3] = color.a;
  return (0);
}
/*
** Swap the two vector if from.x is lower than to.x
*/
static void	swaper(sfVector2f *from, sfVector2f *to)
{
  sfVector2f    swp;

  swp = *from;
  *from = *to;
  *to = swp;
}
/*
** Draw a line from "from" to "to" with sfColor "color"
*/
void		my_draw_line(window_t *window, sfVector2f from,
			     sfVector2f to, sfColor color)
{
  float         a;
  float         b;

  if (from.y > to.y)
    swaper(&from, &to);
  while (from.x == to.x && from.y <= to.y)
    my_put_pixel(window, (int)from.x, (int)from.y++, color);
  if (from.x > to.x)
    swaper(&from, &to);
  while (from.y == to.y && from.x <= to.x)
    my_put_pixel(window, (int)from.x++, (int)from.y, color);
  a = (to.y - from.y) / (to.x - from.x);
  b = from.y - (a * from.x);
  while ((a <= 0.5 || a >= -0.5) && from.x <= to.x)
  {
    from.y = a * from.x + b;
    my_put_pixel(window, (int)from.x, (int)from.y, color);
    from.x += 0.2;
  }
  while ((a >= 0.5 || a <= -0.5) && from.y <= to.y)
  {
    from.x = a * from.x + b;
    my_put_pixel(window, (int)from.x, (int)from.y, color);
    from.y += 0.2;
  }
}
