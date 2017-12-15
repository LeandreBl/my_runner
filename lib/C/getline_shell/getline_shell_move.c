/*
** EPITECH PROJECT, 2017
** getline_shell
** File description:
** move
*/

#include "my.h"
#include "getline_shell.h"

void		move_and_add(char *s, int cur, char ch)
{
  int		i;

  i = my_strlen(s);
  while (i > cur)
    {
      s[i] = s[i - 1];
      i--;
    }
  s[cur] = ch;
}

void		move_and_ret(char *s, int cur)
{
  int		i;

  i = cur - 1;
  while (s[i] != 0)
    {
      s[i] = s[i + 1];
      i++;
    }
}
