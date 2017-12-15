/*
** EPITECH PROJECT, 2017
** getline_shell
** File description:
** hist
*/

#include "my.h"
#include "defines.h"
#include "getline_shell.h"

void		new_hist(t_curset *curset, int dir)
{
  int		len;

  len = tablen(curset->cmds);
  shift_right(curset->s, 1);
  while (curset->hist >= 0 && curset->hist < len
	 && my_strcmp(curset->s, curset->cmds[curset->hist]) == 0)
    curset->hist += dir;
  if (curset->hist < 0)
    curset->hist = 0;
  if (curset->hist < len && curset->hist >= 0)
  {
    sfree(&curset->s);
    curset->s = my_strdup(curset->cmds[curset->hist]);
  }
  if (curset->hist >= len)
  {
    curset->hist = len;
    sfree(&curset->s);
    curset->s = my_calloc(2);
  }
  if (curset->hist == len)
    zeros(curset->s, my_strlen(curset->s));
}
