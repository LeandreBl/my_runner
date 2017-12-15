/*
** epur_str.c for epur_str in /home/leandre/libmy
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Mar 13 14:38:15 2017 Léandre Blanchard
** Last update Thu Apr 27 00:25:44 2017 Léandre Blanchard
*/

#include "my.h"

int		epur_str(char *str)
{
  int		i;

  i = 0;
  while (str[i] == ' ' || str[i] == '\t')
    shift_left(str, 1);
  while (str[i] != 0)
  {
    while ((str[i] == ' ' || str[i] == '\t')
	   && (str[i + 1] == ' ' || str[i + 1] == '\t'))
      shift_left(str + i, 1);
    ++i;
  }
  if (my_strlen(str) > 0)
    while (str[my_strlen(str) - 1] == ' ' || str[my_strlen(str) - 1] == '\t')
      shift_right(str, 1);
  return (0);
}
