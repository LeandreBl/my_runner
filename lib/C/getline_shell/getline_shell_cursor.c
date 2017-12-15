/*
** EPITECH PROJECT, 2017
** getline_shell
** File description:
** cursor
*/

#include "my.h"
#include "defines.h"
#include "getline_shell.h"
#include "colors.h"

void                    backspace(int size)
{
  int                   i;

  i = 0;
  while (i < size + 1)
    {
      write(1, " ", 1);
      i++;
    }
  while (i > 0)
    {
      write(1, "\b", 1);
      i--;
    }
}

int                     ret_back(t_curset *curset)
{
  if (curset->ch != 127)
    return (1);
  if (my_strlen(curset->s) < 1)
    return (1);
  move_and_ret(curset->s, curset->cur);
  curset->cur = curset->cur - 1;
  return (0);
}

int                     cur_end(t_curset *curset)
{
  static char           keys[3] = "\0\0\0";

  keys[0] = keys[1];
  keys[1] = keys[2];
  keys[2] = curset->ch;
  if (keys[0] == 27 && keys[1] == 'O' && keys[2] == 'F')
    {
      shift_right(curset->s, 1);
      zeros(keys, 3);
      curset->cur = my_strlen(curset->s);
      return (0);
    }
  return (1);
}

int                     cur_home(t_curset *curset)
{
  static char           keys[3] = "\0\0\0";

  keys[0] = keys[1];
  keys[1] = keys[2];
  keys[2] = curset->ch;
  if (keys[0] == 27 && keys[1] == 'O' && keys[2] == 'H')
    {
      shift_right(curset->s, 1);
      zeros(keys, 3);
      curset->cur = 0;
      return (0);
    }
  return (1);
}

void                    print_cur(int cur, char *s, const char *prompt)
{
  int                   i;

  mprintf("\r");
  backspace(my_strlen(prompt) + my_strlen(s));
  disp_prompt(prompt);
  mprintf("%s", s);
  i = my_strlen(s);
  while (i > 0)
    {
      mprintf("\b");
      i--;
    }
  while (i < cur)
    {
      mprintf("%c", s[i]);
      i++;
    }
}
