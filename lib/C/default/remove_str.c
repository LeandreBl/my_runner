/*
** remove_str.c for remove_char in /home/leandre/lbl-libc/C
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Sep  8 10:03:54 2017 Léandre Blanchard
** Last update Fri Oct 13 11:04:36 2017 Leandre Blanchard
*/

#include "my.h"

int		remove_str(char *src, const char *del)
{
  char		*pos;
  int		len;

  if (src == NULL || my_strlen(del) == 0)
    return (-1);
  len = my_strlen(del);
  while ((pos = my_strstr(src, del)) != NULL)
    shift_left(pos, len);
  return (0);
}
