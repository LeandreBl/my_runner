/*
** my_calloc.c for calloc in /home/leandre/Rushs/scroller
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun Apr  2 21:33:39 2017 Léandre Blanchard
** Last update Tue Oct 24 21:36:10 2017 Léandre Blanchard
*/

#include <stdlib.h>

#include "my.h"

void		*my_calloc(size_t size)
{
  void		*s;

  s = malloc(size);
  if (s == NULL)
    return (NULL);
  zeros(s, size);
  return (s);
}
