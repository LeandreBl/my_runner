/*
** my_revstr.c for my_revstr in /home/lblanchard/CPool_Day06
**
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.eu
**
** Started on  Fri Oct  7 11:01:26 2016 Leandre Blanchard
** Last update Wed Oct 25 21:11:12 2017 Léandre Blanchard
*/

#include "my.h"

char	*revstr(char *str)
{
  int	i;
  char	c;
  int	len;

  i = 0;
  if (str == NULL)
    return (NULL);
  len = my_strlen(str);
  while (i < len / 2)
    {
      c = *(str + i);
      *(str + i) = *(str + len - i - 1);
      *(str + len - i - 1) = c;
      i = i + 1;
    }
  return (str);
}
