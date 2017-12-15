/*
** max_len.c for max_len in /home/leandre
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu May 25 19:55:56 2017 Léandre Blanchard
** Last update Thu May 25 19:57:13 2017 Léandre Blanchard
*/

#include "my.h"

int		max_len(char **tab)
{
  int		i;
  int		max;
  int		len;

  i = 0;
  max = 0;
  len = 0;
  while (tab != NULL && tab[i] != NULL)
    {
      len = my_strlen(tab[i]);
      if (len > max)
	max = len;
      i++;
    }
  return (max);
}
