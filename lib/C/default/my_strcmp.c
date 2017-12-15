/*
** my_strcmp.c for my_strcmp in /home/lblanchard/CPool_Day06
**
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
**
** Started on  Thu Oct  6 11:19:22 2016 Leandre Blanchard
** Last update Wed Oct 25 21:15:07 2017 Léandre Blanchard
*/

#include <stdlib.h>

int	my_strcmp(const char *s1, const char *s2)
{
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while (*s1 && *s2 && *s1 == *s2)
    {
      ++s1;
      ++s2;
    }
  if (*s1 - *s2 < 0)
    return (-1);
  if (*s1 - *s2 > 0)
    return (1);
  return (0);
}

int	my_strncmp(const char *s1, const char *s2, int n)
{
  if (s1 == NULL || s2 == NULL)
    return (-1);
  --n;
  while (*s1 && *s2 && *s1 == *s2 && n)
  {
    ++s1;
    ++s2;
    --n;
  }
  return (*s1 - *s2);
}
