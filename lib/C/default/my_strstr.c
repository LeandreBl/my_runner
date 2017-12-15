/*
** my_strstr.c for my_strstr in /home/lblanchard/CPool_Day06
**
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
**
** Started on  Thu Oct  6 11:19:22 2016 Leandre Blanchard
** Last update Fri Oct 13 11:36:52 2017 Leandre Blanchard
*/

#include <stdlib.h>

#include "my.h"

char	*my_strstr(const char *str, const char *to_find)
{
  int	i;
  int	len;

  if (str == NULL || to_find == NULL)
    return ((char *)str);
  i = 0;
  len = my_strlen(to_find);
  while (str[i] != 0)
    {
      if (my_strncmp(str + i, to_find, len) == 0)
	return ((char *)(str + i));
      ++i;
    }
  return (NULL);
}
