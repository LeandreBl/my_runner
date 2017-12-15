/*
** realloc.c for mnishell in /home/leandre/System_unix/PSU_2016_minishell1
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sat Jan 21 17:29:08 2017 Léandre Blanchard
** Last update Wed Oct 25 21:19:04 2017 Léandre Blanchard
*/

#include <stdlib.h>

#include "my.h"

char		**tab_realloc(char **src, int add)
{
  char		**tab;
  int		len;
  int		i;

  i = 0;
  len = tablen(src);
  if ((tab = malloc(sizeof(char *) * (len + add + 1))) == NULL)
    return (NULL);
  while (src[i] != NULL)
    {
      tab[i] = src[i];
      ++i;
    }
  while (i < len + add)
    tab[i++] = NULL;
  return (tab);
}

char		*my_frealloc(char *str, int size)
{
  char		*new;

  if ((new = my_realloc(str, size)) == NULL)
    return (NULL);
  sfree(&str);
  return (new);
}

char            *my_realloc(const char *str, int size)
{
  char          *dest;

  if (str == NULL)
    return (my_calloc(size));
  if ((dest = my_calloc(sizeof(char) * (my_strlen(str) + size))) == NULL)
    return (NULL);
  my_strcpy(dest, str);
  return (dest);
}
