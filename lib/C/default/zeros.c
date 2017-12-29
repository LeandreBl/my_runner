/*
** zeros.c for zeros in /home/leandre/Prog_elem/CPE_2016_corewar_bootstrap
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Feb 27 14:30:19 2017 Léandre Blanchard
** Last update Sun Apr 30 17:27:20 2017 Léandre Blanchard
*/

#include <stddef.h>

int		zeros(void *ptr, size_t size)
{
  char		*p;
  size_t	i;

  i = 0;
  p = ptr;
  if (p == NULL)
    return (-1);
  while (i < size)
    p[i++] = 0;
  return (0);
}
