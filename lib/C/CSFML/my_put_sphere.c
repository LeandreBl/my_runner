/*
** my_put_sphere.c for put_sphere in /home/leandre/Rushs/scroller
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun Apr  2 16:00:05 2017 Léandre Blanchard
** Last update Sat Jun  3 16:55:16 2017 Léandre Blanchard
*/

#include "csfml.h"

/*
** Draw a sphere of size "size" at position "pos" with color "color"
** on the window_t->pixels
** this fonction does not return
*/
void                    draw_circle(window_t* window, sfVector2f pos,
				    int size, sfColor color)
{
  int                   i;
  int                   j;
  float                 dist;

  i = -size;
  dist = 0;
  while (i < size)
    {
      j = -size;
      while (j < size)
	{
	  dist = sqrt(((pos.x - pos.x + j) * (pos.x - pos.x + j))
		      + ((pos.y - pos.y + i) * (pos.y - pos.y + i)));
	  if (dist < size)
	    my_put_pixel(window, pos.x + j, pos.y + i, color);
	  j++;
	}
      i++;
    }
}

