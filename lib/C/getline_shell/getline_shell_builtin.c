/*
** EPITECH PROJECT, 2017
** getline shell
** File description:
** key cmd
*/

#include "getline_shell.h"
#include "my.h"
#include "defines.h"
#include "colors.h"

int                     ctrl_c(t_curset *curset)
{
  if (curset->ch == 3)
    {
      zeros(curset->s, my_strlen(curset->s));
      mprintf("\n");
      disp_prompt(curset->prompt);
      return (0);
    }
  return (1);
}

int                     ctrl_d(t_curset *curset)
{
  if (curset->ch != 4)
    return (1);
  if (curset->s[0] == 0)
    {
      sfree(&curset->s);
      curset->s = NULL;
      return (0);
    }
  return (1);
}

int                     ctrl_l(t_curset *curset)
{
  if (curset->ch != 12)
    return (-1);
  mprintf(CLEARTOP);
  return (0);
}

int                     alt_l(t_curset *curset)
{
  static char           prev;

  if (prev == 27 && curset->ch == 'l')
    {
      sfree(&curset->s);
      mprintf("\r");
      disp_prompt(curset->prompt);
      mprintf("ls\n");
      prev = 0;
      return (0);
    }
  prev = curset->ch;
  return (1);
}

int			ctrl_k(t_curset *curset)
{
  char			*to_clear;

  if (curset->ch == 11)
    {
      to_clear = curset->s + curset->cur;
      zeros(to_clear, my_strlen(to_clear));
      curset->cur = my_strlen(curset->s);
      return (0);
    }
  return (1);
}
