/*
** my_memcpy.c for memcopy in /home/leandre/libmy/C
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Aug 31 04:03:33 2017 Léandre Blanchard
** Last update Sat Oct 21 19:04:35 2017 Léandre Blanchard
*/

#include <stdlib.h>

int		memcopy(void *to, const void *from, int size)
{
  int		i;

  if (from == NULL || to == NULL)
    return (1);
  i = 0;
  while (i < size)
    {
      *(char *)(to + i) = *(char *)(from + i);
      ++i;
    }
  return (0);
}
