/*
** replace.c for replace in /home/lblanchard/TEST
** 
** Made by Leandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Oct 13 10:33:07 2017 Leandre Blanchard
** Last update Fri Oct 13 11:23:04 2017 Leandre Blanchard
*/

#include "my.h"

char			*replace(char *src, const char *str, const char *repl)
{
  char			*pos;
  int			prev;

  if (src == NULL || str == NULL || my_strlen(repl) == 0)
    return (src);
  pos = src;
  prev = 0;
  while ((pos = my_strstr(pos, str)) != NULL)
    {
      prev = pos - src;
      shift_left(pos, my_strlen(str));
      if ((src = insert(src, repl, pos - src)) == NULL)
	return (NULL);
      pos = src + prev + 1;
    }
  return (src);
}
