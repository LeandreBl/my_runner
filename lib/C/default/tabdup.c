/*
** tabdup.c for tabdup in /home/leandre/libmy
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu May 25 19:35:48 2017 Léandre Blanchard
** Last update Wed Oct 25 21:20:03 2017 Léandre Blanchard
*/

#include <stdlib.h>

#include "my.h"

char		**tabdup(char **tab)
{
  int		i;
  char		**new;

  i = 0;
  if (tab == NULL)
    return (NULL);
  if ((new = malloc(sizeof(char *) * (tablen(tab) + 1))) == NULL)
    return (NULL);
  while (tab != NULL && tab[i] != NULL)
    {
      if ((new[i] = my_strdup(tab[i])) == NULL)
	return (NULL);
      i++;
    }
  new[i] = NULL;
  return (new);
}
