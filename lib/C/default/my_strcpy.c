/*
** my_strcpy.c for my_strcpy in /home/lblanchard/lbl-libc/C
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Tue Nov  8 19:58:41 2016 Leandre Blanchard
** Last update Wed Oct 25 21:14:41 2017 Léandre Blanchard
*/

#include <unistd.h>

int	my_strcpy(char *dest, const char *src)
{
  int	i;

  if (dest == NULL || src == NULL)
    return (-1);
  i = 0;
  while (*(src + i))
    {
      *(dest + i) = *(src + i);
      ++i;
    }
  *(dest + i) = *(src + i);
  return (0);
}

char	*my_strncpy(char *dest, const char *src, int n)
{
  int	i;

  i = 0;
  if (dest == NULL || src == NULL)
    return (NULL);
  while (n > 0 && *(src + i))
  {
    *(dest + i) = *(src + i);
    i = i + 1;
    n = n - 1;
  }
  if (n > 0)
    *(dest + i) = ('\0');
  return (dest);
}
