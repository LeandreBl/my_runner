/*
** my_strdup.c for my_strdup in /home/lblanchard/CPool_Day08
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Wed Oct 12 09:15:56 2016 Leandre Blanchard
** Last update Thu Oct 12 18:18:54 2017 Leandre Blanchard
*/

#include <unistd.h>

#include "my.h"

char	*my_strdup(const char *src)
{
  char	*dest;

  if (src == NULL)
    return (NULL);
  dest = my_calloc(sizeof(char) * (my_strlen(src) + 1));
  if (dest == NULL)
    return (NULL);
  my_strcpy(dest, src);
  return (dest);
}

char	*my_strndup(const char *src, int size)
{
  char	*dest;

  if (size <= 0 || src == NULL)
    return (NULL);
  dest = my_calloc(sizeof(char) * (size + 1));
  if (dest == NULL)
    return (NULL);
  my_strncpy(dest, src, size);
  return (dest);
}
