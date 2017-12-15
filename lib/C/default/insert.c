/*
** insert.c for insert in /home/leandre/TEST_FOLDER
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed Sep  6 16:57:05 2017 Léandre Blanchard
** Last update Fri Oct 13 10:55:53 2017 Leandre Blanchard
*/

#include <stdlib.h>

#include "my.h"

static char	*too_far(char *src, const char *str, int pos)
{
  char		*dest;

  if ((dest = my_calloc(pos + my_strlen(str) + 1)) == NULL)
    return (NULL);
  my_strcpy(dest, src);
  my_strcpy(dest + pos, str);
  sfree(&src);
  return (dest);
}

char		*insert(char *src, const char *str, int pos)
{
  char		*dest;
  int		len;

  if (str == NULL || src == NULL)
    return (src);
  len = my_strlen(src);
  if (pos > len)
    return (too_far(src, str, pos));
  if ((dest = my_calloc(my_strlen(src) + my_strlen(str) + 2)) == NULL)
    return (NULL);
  my_strncpy(dest, src, pos);
  my_strcpy(dest + pos, str);
  my_strcpy(dest + pos + my_strlen(str), src + pos);
  sfree(&src);
  return (dest);
}
