/*
** char_to_binary.c for car_to_binary in /home/leandre/TEST_FOLDER
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue Sep 12 15:37:45 2017 Léandre Blanchard
** Last update Tue Sep 12 15:41:18 2017 Léandre Blanchard
*/

#include "my.h"

char		*char_to_bin(char n)
{
  int		i;
  char		*binary;

  if ((binary = my_calloc(9)) == NULL)
    return (NULL);
  i = 0;
  while (i < 8)
    {
      if ((n << i) & 0x80)
	binary[i] = '1';
      else
	binary[i] = '0';
      ++i;
    }
  return (binary);
}

char		bin_to_char(const char *binary)
{
  char		n;
  int		i;

  i = 0;
  n = 0;
  while (i < 8)
    {
      n <<= 1;
      if (binary[i] == '1')
	n ^= 1;
      ++i;
    }
  return (n);
}
