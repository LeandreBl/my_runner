/*
** my_malloc.c for my_malloc in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri May 26 16:32:07 2017 Léandre Blanchard
** Last update Fri May 26 16:32:08 2017 Léandre Blanchard
*/

#include <unistd.h>
#include <stddef.h>

void			*first;

void			free_my(void)
{
  brk(first);
}

void			*my_malloc(size_t size)
{
  static int		calls;
  void			*ptr;

  if (calls == 0)
    first = sbrk(0);
  ptr = sbrk(size);
  calls++;
  return (ptr);
}
