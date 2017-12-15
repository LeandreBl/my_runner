/*
** my_strcat.c for my_strcat in /home/lblanchard/CPool_Day07
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Tue Oct 11 09:27:45 2016 Leandre Blanchard
** Last update Mon Oct 30 22:42:38 2017 Léandre Blanchard
*/

#include "my.h"

int	my_strcat(char *dest, const char *src)
{
  if (dest == NULL || src == NULL)
    return (-1);
  while (*dest)
    ++dest;
  while ((*dest = *src))
    {
      ++dest;
      ++src;
    }
  return (0);
}

int	my_strncat(char *dest, const char *src, int nb)
{
  if (dest == NULL || src == NULL)
    return (-1);
  while (*dest)
    ++dest;
  while ((*dest = *src) && nb > 0)
  {
    ++dest;
    ++src;
    --nb;
  }
  return (0);
}
