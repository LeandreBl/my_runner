/*
** rev_tab.c for rev_tab in /home/leandre/libmy
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu May 25 19:13:10 2017 Léandre Blanchard
** Last update Wed Oct 25 21:19:36 2017 Léandre Blanchard
*/

#include <stdlib.h>
#include "my.h"

int		revtab(char **tab)
{
  int		i;
  int		len;
  char		*temp;

  if (tab == NULL)
    return (-1);
  len = tablen(tab);
  i = 0;
  while (i != len / 2)
    {
      temp = tab[i];
      tab[i] = tab[len - 1 - i];
      tab[len - 1 - i] = temp;
      i++;
    }
  return (0);
}
